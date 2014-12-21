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
#include <bitset>
#include <iostream>
#include <sstream>

int main() {
    std::ostringstream os;

    // decimal and hexadecimal value
    os << "dec: " << 15 << std::hex << " hex: " << 15 << '\n';
    std::cout << os.str() << '\n';

    // append floating value and bitset
    std::bitset<15> b(5789);
    os << "float: " << 4.67 << " bitset: " << b << '\n';

    // overwrite with octal value
    os.seekp(0);
    os << "oct: " << std::oct << 15;
    std::cout << os.str() << '\n';
}
