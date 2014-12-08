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
#include <string>
#include <tuple>
#include <utility>

int main() {
    // create a four-element tuple
    // - elements are initialized with default value (0 for fundamental types)
    std::tuple<std::string, int, int, std::complex<double>> t;

    // create and initialize a tuple explicitly
    std::tuple<int, double, std::string> t1(41, 6.3, "nico");

    // ``iterate'' over elements
    std::cout << std::get<0>(t1) << ' ';
    std::cout << std::get<1>(t1) << ' ';
    std::cout << std::get<2>(t1) << '\n';

    // create tuple with make_tuple()
    // - auto declares t2 with type of right-hand side
    // - thus, type of t2 is tuple
    auto t2 = std::make_tuple(22, 44, "nico");

    // assign second value in t2 to t1
    std::get<1>(t1) = std::get<1>(t2);

    // comparison and assignment
    // - including type conversion from tuple<int, int, const char*>
    //   to tuple<int, double, std::string>
    if (t1 < t2) {  // compares value for value
        t1 = t2;    // OK, assigns value for value
    }
}
