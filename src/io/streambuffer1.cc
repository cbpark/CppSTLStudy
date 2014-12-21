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
#include <fstream>
#include <iostream>

int main() {
    // stream for hexadecimal standard output
    std::ostream hexout(std::cout.rdbuf());
    hexout.setf(std::ios::hex, std::ios::basefield);
    hexout.setf(std::ios::showbase);

    // switch between decimal and hexadecimal output
    hexout << "hexout: " << 177 << ' ';
    std::cout << "cout: " << 177 << ' ';
    hexout << "hexout: " << -49 << ' ';
    std::cout << "cout: " << -49 << ' ';
    hexout << '\n';
}
