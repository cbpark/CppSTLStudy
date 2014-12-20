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
#include <string>

int main() {
    std::string data = "<person>\n"
        " <first>Nico</first>\n"
        " <last>Josuttis</last>\n"
        " </person>\n";

    std::regex reg("<(.*)>(.*)</(\\1)>");

    // iterate over all matches
    auto pos = data.cbegin();
    auto end = data.cend();
    std::smatch m;
    for ( ; std::regex_search(pos, end, m, reg); pos = m.suffix().first) {
        std::cout << "match:  " << m.str() << '\n';
        std::cout << " tag:   " << m.str(1) << '\n';
        std::cout << " value: " << m.str(2) << '\n';
    }
}
