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
    // case-insensitive find LaTeX index entries
    std::string pat1 = R"(\\.*index\{([^}]*)\})";       // first capture group
    std::string pat2 = R"(\\.*index\{(.*)\}\{(.*)\})";  // 2nd and 3rd capture group
    std::regex pat(pat1 + "\n" + pat2,
                   std::regex_constants::egrep | std::regex_constants::icase);

    // initialize string with characters from standard input:
    std::string data((std::istreambuf_iterator<char>(std::cin)),
                     std::istreambuf_iterator<char>());

    // search and print matching index entries:
    std::smatch m;
    auto pos = data.cbegin();
    auto end = data.cend();
    for ( ; std::regex_search(pos, end, m, pat); pos = m.suffix().first) {
        std::cout << "match: " << m.str() << '\n';
        std::cout << "  val: " << m.str(1) + m.str(2) << '\n';
        std::cout << "  see: " << m.str(3) << '\n';
    }
}
