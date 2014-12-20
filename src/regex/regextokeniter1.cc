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

    // iterate over all matches (using a regex_token_iterator):
    std::sregex_token_iterator pos(data.cbegin(), data.cend(),  // sequence
                                   reg,                         // token separator
                                   {0, 2});  // 0: full match, 2: second substring
    std::sregex_token_iterator end;
    for ( ; pos != end ; ++pos) {
        std::cout << "match:  " << pos->str() << '\n';
    }
    std::cout << '\n';

    std::string names = "nico, jim, helmut, paul, tim, john paul, rita";
    std::regex sep("[ \t\n]*[,;.][ \t\n]*");  // separated by , ; or . and spaces
    std::sregex_token_iterator p(names.cbegin(), names.cend(),  // sequence
                                 sep,                           // separator
                                 -1);  // -1: values between separators
    std::sregex_token_iterator e;
    for ( ; p != e ; ++p) {
        std::cout << "name:  " << *p << '\n';
    }
}
