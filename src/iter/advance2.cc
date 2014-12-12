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
#include <string>

int main() {
    std::istream_iterator<std::string> cin_pos(std::cin);
    std::ostream_iterator<std::string> cout_pos(std::cout, " ");

    // while input is not at the end of file
    // - write every third string
    while (cin_pos != std::istream_iterator<std::string>()) {
        // ignore the following two strings
        std::advance(cin_pos, 2);

        // read and write the third string
        if (cin_pos != std::istream_iterator<std::string>()) {
            *cout_pos++ = *cin_pos++;
        }
    }
    std::cout << '\n';
}
