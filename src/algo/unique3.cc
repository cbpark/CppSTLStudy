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
#include <algorithm>
#include <iostream>
#include <iterator>

bool BothSpaces(char elem1, char elem2) {
    return elem1 == ' ' && elem2 == ' ';
}

int main() {
    // don't skip leading whitespaces by default
    std::cin.unsetf(std::ios::skipws);

    // copy standard input to standard output
    // - while compressing spaces
    std::unique_copy(std::istream_iterator<char>(std::cin),   // beginning of source: cin
                     std::istream_iterator<char>(),           // end of source: end-of-file
                     std::ostream_iterator<char>(std::cout),  // destination: cout
                     BothSpaces);                             // duplicate criterion
}
