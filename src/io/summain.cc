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
#include "sum2a.h"
#include <cstdlib>
#include <exception>
#include <iostream>

int main() {
    double sum;

    try {
        sum = mylib::ReadAndProcessSum(std::cin);
    } catch (const std::ios::failure& error) {
        std::cerr << "I/O exception: " << error.what() << '\n';
        return EXIT_FAILURE;
    } catch (const std::exception& error) {
        std::cerr << "standard exception: " << error.what() << '\n';
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "unknown exception\n";
        return EXIT_FAILURE;
    }

    // print sum
    std::cout << "sum: " << sum << '\n';
}
