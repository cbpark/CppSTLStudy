/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <regex>

void Out(bool b) {
    std::cout << (b ? "found" : "not found") << '\n';
}

int main() {
    // find XML/HTML-tagged value (using default syntax)
    std::regex reg1("<.*>.*</.*>");
    bool found = std::regex_match("<tag>value</tag>",  // data
                                  reg1);               // regular expression
    Out(found);

    // find XML/HTML-tagged value (tags before and after the value must match)
    std::regex reg2("<(.*)>.*</\\1>");
    found = std::regex_match("<tag>value</tag>",  // data
                             reg2);               // regular expression
    Out(found);

    // find XML/HTML-tagged value (using grep syntax)
    std::regex reg3("<\\(.*)\\)>.*</\\1>", std::regex_constants::grep);
    found = std::regex_match("<tag>value</tag>",  // data
                             reg3);               // regular expression
    Out(found);

    // use C-string as regular expression (needs explicit cast to regex)
    found = std::regex_match("<tag>value</tag>",            // data
                             std::regex("<(.*)>.*</\\1"));  // regular expression
    Out(found);
    std::cout << '\n';

    // std::regex_match() versus std::regex_search()
    found = std::regex_match("XML tag: <tag>value</tag>",
                             std::regex("<(.*)>.*</\\1>"));       // fails to match
    Out(found);
    found = std::regex_match("XML tag: <tag>value</tag>",
                             std::regex(".*<(.*)>.*</\\1>.*"));   // matches
    Out(found);
    found = std::regex_search("XML tag: <tag>value</tag>",
                              std::regex("<(.*)>.*</\\1>"));      // matches
    Out(found);
    found = std::regex_search("XML tag: <tag>value</tag>",
                              std::regex(".*<(.*)>.*</\\1>.*"));  // matches
    Out(found);
}
