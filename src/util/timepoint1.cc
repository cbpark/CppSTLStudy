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
#include "timepoint.h"

#include <chrono>
#include <iostream>

int main() {
    auto tp1 = MakeTimePoint(2010, 01, 01, 00, 00);
    std::cout << AsString(tp1) << '\n';

    auto tp2 = MakeTimePoint(2011, 05, 23, 13, 44);
    std::cout << AsString(tp2) << '\n';
}
