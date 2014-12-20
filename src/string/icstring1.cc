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
#include "icstring.h"

int main() {
    icstring s1("hallo");
    icstring s2("otto");
    icstring s3("hALLo");

    std::cout << std::boolalpha;
    std::cout << s1 << " == " << s2 << " : " << (s1 == s2) << '\n';
    std::cout << s1 << " == " << s3 << " : " << (s1 == s3) << '\n';

    icstring::size_type idx = s1.find("All");
    if (idx != icstring::npos) {
        std::cout << "index of \"All\" in \"" << s1 << "\": "
                  << idx << '\n';
    }
    else {
        std::cout << "\"All\" not found in \"" << s1 << '\n';
    }
}
