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
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string data = "XML tag: <tag-name>the value</tag-name>.";
    std::cout << "data:             " << data << "\n\n";

    std::smatch m;  // for returned details of the match
    bool found = std::regex_search(data,
                                   m,
                                   std::regex("<(.*)>(.*)</(\\1)>"));

    // print match details
    std::cout << "m.empty():        " << std::boolalpha << m.empty() << '\n';
    std::cout << "m.size():         " << m.size() << '\n';
    if (found) {
        std::cout << "m.str():          " << m.str() << '\n';
        std::cout << "m.length():       " << m.length() << '\n';
        std::cout << "m.position():     " << m.position() << '\n';
        std::cout << "m.prefix().str(): " << m.prefix().str() << '\n';
        std::cout << "m.suffix().str(): " << m.suffix().str() << "\n\n";

        // iterating over all matches (using the match index)
        for (unsigned int i = 0; i < m.size(); ++i) {
            std::cout << "m[" << i << "].str():       " << m[i].str() << '\n';
            std::cout << "m.str(" << i << "):         " << m.str(i) << '\n';
            std::cout << "m.position(" << i << "):    " << m.position() << '\n';
        }
        std::cout << '\n';

        // iterating over all matches (using iterators)
        std::cout << "matches:\n";
        for (auto pos = m.begin(); pos != m.end(); ++pos) {
            std::cout << ' ' << *pos << ' ';
            std::cout << "(length: " << pos->length() << ")\n";
        }
    }
}
