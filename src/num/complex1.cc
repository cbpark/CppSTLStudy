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
#include <iostream>

int main() {
    // complex number with real and imaginary parts
    // - real part: 4.0
    // - imaginary part: 3.0
    std::complex<double> c1(4.0, 3.0);

    // create complex number from polar coordinates
    // - magnitude: 5.0
    // - phase angle: 0.75
    std::complex<double> c2(std::polar(5.0, 0.75));

    // print complex numbers with real and imaginary parts
    std::cout << "c1: " << c1 << '\n';
    std::cout << "c2: " << c2 << '\n';

    // print complex numbers as polar coordinates
    std::cout << "c1: magnitude: " << std::abs(c1)
              << " (squared magnitude: " << std::norm(c1) << ") "
              << " phase angle " << std::arg(c1) << '\n';
    std::cout << "c2: magnitude: " << std::abs(c2)
              << " (squared magnitude: " << std::norm(c2) << ") "
              << " phase angle " << std::arg(c2) << '\n';

    // print complex conjugate
    std::cout << "c1 conjugated: " << std::conj(c1) << '\n';
    std::cout << "c2 conjugated: " << std::conj(c2) << '\n';

    // print result of a computation
    std::cout << "4.4 + c1 * 1.8: " << 4.4 + c1 * 1.8 << '\n';

    // print sum of c1 and c2:
    // - note: different types
    std::cout << "c1 + c2:        "
              << c1 + std::complex<double>(c2.real(), c2.imag()) << '\n';

    // add square root of c1 to c1 and print the result
    std::cout << "c1 += sqrt(c1): "
              << (c1 += std::sqrt(c1)) << '\n';
}
