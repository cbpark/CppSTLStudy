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
#include <ratio>

int main() {
    using FiveThirds = std::ratio<5, 3>;
    std::cout << FiveThirds::num << "/" << FiveThirds::den << '\n';

    using AlsoFiveThirds = std::ratio<25, 15>;
    std::cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << '\n';

    std::ratio<42, 42> one;
    std::cout << one.num << "/" << one.den << '\n';

    std::ratio<0> zero;
    std::cout << zero.num << "/" << zero.den << '\n';

    using Neg = std::ratio<7, -3>;
    std::cout << Neg::num << "/" << Neg::den << '\n';
}
