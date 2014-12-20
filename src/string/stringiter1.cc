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
#include <cctype>
#include <iostream>
#include <regex>
#include <string>

int main() {
    // create a string
    std::string s("The zip code of Braunschweig in Germany is 38100");
    std::cout << "original: " << s << '\n';

    // lowercase all characters
    std::transform(s.cbegin(), s.cend(),  // source
                   s.begin(),             // destination
                   [] (char c) {          // operation
                       return std::tolower(c);
                   });
    std::cout << "lowered:  " << s << '\n';

    // uppercase all characters
    std::transform(s.cbegin(), s.cend(),  // source
                   s.begin(),             // destination
                   [] (char c) {          // operation
                       return std::toupper(c);
                   });
    std::cout << "uppered:  " << s << '\n';

    // search case-insensitive for Germany
    // std::string g("Germany");
    // std::string::const_iterator pos;
    // pos = std::search(s.cbegin(), s.cend(),    // source string in which to search
    //                   g.cbegin(), g.cend(),    // substring to search
    //                   [] (char c1, char c2) {  // comparison criterion
    //                       return std::toupper(c1) == std::toupper(c2);
    //                   });
    // if (pos != s.cend()) {
    //     std::cout << "substring \"" << g << "\" found at index "
    //               << pos - s.cbegin() << '\n';
    // }
    std::regex pat("Germany",                     // expression to search for
                   std::regex_constants::icase);  // search case-insensitive
    std::smatch m;
    if (std::regex_search(s, m, pat)) {
        std::cout << "substring \"Germany\" found at index "
                  << m.position() << '\n';
    }
}
