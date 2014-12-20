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
#include <iterator>
#include <regex>
#include <string>

int main() {
    std::string data = "<person>\n"
        " <first>Nico</first>\n"
        " <last>Josuttis</last>\n"
        " </person>\n";

    std::regex reg("<(.*)>(.*)</(\\1)>");

    // print data with replacement for matched patterns
    std::cout << std::regex_replace(data,                  // data
                                    reg,                   // regular expression
                                    "<$1 value=\"$2\"/>")  // replacement
              << '\n';

    // same using sed syntax
    std::cout << std::regex_replace(data,                              // data
                                    reg,                               // regular expression
                                    "<\\1 value=\"\\2\"/>",            // replacement
                                    std::regex_constants::format_sed)  // format flag
              << '\n';

    // use iterator interface, and
    // - format_no_copy:    don't copy characters that don't match
    // - format_first_only: replace only the first match found
    std::string res2;
    std::regex_replace(std::back_inserter(res2),             // destination
                       data.begin(), data.end(),             // source range
                       reg,                                  // regular expression
                       "<$1 value=\"$2\"/>",                 // replacement
                       std::regex_constants::format_no_copy  // format flags
                       | std::regex_constants::format_first_only);
    std::cout << res2 << '\n';
}
