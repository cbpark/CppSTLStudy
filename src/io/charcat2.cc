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
    // input stream buffer iterator for cin
    std::istreambuf_iterator<char> inpos(std::cin);

    // end-of-stream iterator
    std::istreambuf_iterator<char> endpos;

    // output stream buffer iterator for cout
    std::ostreambuf_iterator<char> outpos(std::cout);

    // while input iterator is valid
    while (inpos != endpos) {
        *outpos = *inpos;  // assign its value to the output iterator
        ++inpos;
        ++outpos;
    }
}
