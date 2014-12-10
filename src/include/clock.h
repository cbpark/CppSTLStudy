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
#ifndef SRC_INCLUDE_CLOCK_H_
#define SRC_INCLUDE_CLOCK_H_

#include <chrono>
#include <iostream>
#include <iomanip>
#include <ratio>

template <typename C>
void PrintClockData() {
    std::cout << "- precision: ";
    // if time unit is less or equal one millisecond
    typedef typename C::period P;  // type of time unit
    if (std::ratio_less_equal<P, std::milli>::value) {
        // convert to and print as milliseconds
        typedef typename std::ratio_multiply<P, std::kilo>::type TT;
        std::cout << std::fixed << double(TT::num) / TT::den
                  << " milliseconds\n";
    } else {
        // print as seconds
        std::cout << std::fixed << double(P::num) / P::den
                  << " seconds\n";
    }
    std::cout << "- is_steady: " << std::boolalpha << C::is_steady << '\n';
}

#endif  // SRC_INCLUDE_CLOCK_H_
