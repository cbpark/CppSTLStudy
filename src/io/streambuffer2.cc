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

void HexMultiplicationTable(std::streambuf *buffer, int num) {
    std::ostream hexout(buffer);
    hexout << std::hex << std::showbase;

    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= 10; ++j) {
            hexout << i * j << ' ';
        }
        hexout << '\n';
    }
}  // does NOT close buffer

int main() {
    int num = 5;

    std::cout << "We print " << num
              << " lines hexadecimal\n";

    HexMultiplicationTable(std::cout.rdbuf(), num);

    std::cout << "That was the output of " << num
              << " hexadecimal lines\n";
}
