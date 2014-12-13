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
#include <functional>
#include <iostream>
#include <locale>
#include <string>

using std::placeholders::_1;
using std::placeholders::_2;

char MyToUpper(char c) {
    std::locale loc;
    return std::use_facet<std::ctype<char>>(loc).toupper(c);
}

int main() {
    std::string s("Internationalizatione");
    std::string sub("Nation");

    // search substring case insensitive
    std::string::iterator pos;
    pos = std::search(s.begin(), s.end(),               // string to search in
                      sub.begin(), sub.end(),           // substring to search
                      std::bind(std::equal_to<char>(),  // comparison criterion
                                std::bind(MyToUpper, _1),
                                std::bind(MyToUpper, _2)));
    if (pos != s.end()) {
        std::cout << "\"" << sub << "\" is part of \"" << s << "\"\n";
    }
}
