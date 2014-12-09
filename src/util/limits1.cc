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
#include <limits>
#include <string>

int main() {
    // use textual representation for bool
    std::cout << std::boolalpha;

    // print maximum of integral types
    std::cout << "max(short): " << std::numeric_limits<short>::max() << '\n';
    std::cout << "max(int):   " << std::numeric_limits<int>::max() << '\n';
    std::cout << "max(long):  " << std::numeric_limits<long>::max() << '\n';
    std::cout << '\n';

    // print maximum of floating-point types
    std::cout << "max(float):       "
              << std::numeric_limits<float>::max() << '\n';
    std::cout << "max(double):      "
              << std::numeric_limits<double>::max() << '\n';
    std::cout << "max(long double): "
              << std::numeric_limits<long double>::max() << '\n';
    std::cout << '\n';

    // print whether char is signed
    std::cout << "is_signed(char):  "
              << std::numeric_limits<char>::is_signed << '\n';
    std::cout << '\n';

    // print whether numeric limits for type string exist
    std::cout << "is_specialized(string): "
              << std::numeric_limits<std::string>::is_specialized << '\n';
}
