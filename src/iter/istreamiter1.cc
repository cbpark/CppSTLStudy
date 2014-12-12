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
#include <iterator>

int main() {
    // create istream iterator that reads integers from cin
    std::istream_iterator<int> int_reader(std::cin);

    // create end-of-stream iterator
    std::istream_iterator<int> int_reader_eof;

    // while able to read tokens with istream iterator
    // - write them twice
    while (int_reader != int_reader_eof) {
        std::cout << "once:   "     << *int_reader << '\n';
        std::cout << "once again: " << *int_reader << '\n';
        ++int_reader;
    }
}
