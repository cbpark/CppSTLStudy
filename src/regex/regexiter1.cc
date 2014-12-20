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
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string data = "<person>\n"
        " <first>Nico</first>\n"
        " <last>Josuttis</last>\n"
        "</person>\n";

    std::regex reg("<(.*)>(.*)</(\\1)>");

    // iterate over all matches (using a regex_iterator):
    std::sregex_iterator pos(data.cbegin(), data.cend(), reg);
    std::sregex_iterator end;
    for ( ; pos != end ; ++pos) {
        std::cout << "match:  " << pos->str() << '\n';
        std::cout << " tag:   " << pos->str(1) << '\n';
        std::cout << " value: " << pos->str(2) << '\n';
    }

    // use a regex_iterator to process each matched substring
    // as element in an algorithm:
    std::sregex_iterator beg(data.cbegin(), data.cend(), reg);
    std::for_each(beg, end, [] (const std::smatch& m) {
            std::cout << "match:  " << m.str() << '\n';
            std::cout << " tag:   " << m.str(1) << '\n';
            std::cout << " value: " << m.str(2) << '\n';
        });
}
