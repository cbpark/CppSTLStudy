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
#include <cstdlib>
#include <iostream>

int main() {
    double x, y;

    // print header string
    std::cout << "Multiplication of two floating point values\n";

    // read first operand
    std::cout << "first operand:  ";
    if (!(std::cin >> x)) {
        // input error
        // => error message and exit program with error status
        std::cerr << "error while reading the first floating value\n";
        return EXIT_FAILURE;
    }

    // read second operand
    std::cout << "second operand: ";
    if (!(std::cin >> y)) {
        // input error
        // => error message and exit programs with error status
        std::cerr << "error while reading the second floating value\n";
        return EXIT_FAILURE;
    }

    // print operand and result
    std::cout << x << " times " << y << " equals " << x * y << '\n';
}
