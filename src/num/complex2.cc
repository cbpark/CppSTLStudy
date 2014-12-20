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
#include <complex>
#include <cstdlib>
#include <iostream>
#include <limits>

int main() {
    std::complex<long double> c1, c2;

    while (std::cin.peek() != EOF) {
        // read first complex number
        std::cout << "complex number c1: ";
        std::cin >> c1;
        if (!std::cin) {
            std::cerr << "input error\n";
            return EXIT_FAILURE;
        }

        // read second complex number
        std::cout << "complex number c2: ";
        std::cin >> c2;
        if (!std::cin) {
            std::cerr << "input error\n";
            return EXIT_FAILURE;
        }

        if (c1 == c2) {
            std::cout << "c1 and c2 are equal !\n";
        }

        std::cout << "c1 raised to the c2: " << std::pow(c1, c2) << "\n\n";

        // skip rest of line
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
}
