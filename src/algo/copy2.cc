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
#include "algostuff.h"

int main() {
    // initialize source collection with ``. ..........abcdef..........''
    std::vector<char> source(10, '.');
    for (int c = 'a'; c <= 'f'; c++) {
        source.push_back(c);
    }
    source.insert(source.end(), 10, '.');
    PrintElements(source, "source: ");

    // copy all letters three elements in front of the 'a'
    std::vector<char> c1(source.cbegin(), source.cend());
    std::copy(c1.cbegin() + 10, c1.cbegin() + 16, c1.begin() + 7);
    PrintElements(c1, "c1:     ");

    // copy all letters three elements behind the 'f'
    std::vector<char> c2(source.cbegin(), source.cend());
    std::copy_backward(c2.cbegin() + 10, c2.cbegin() + 16, c2.begin() + 19);
    PrintElements(c2, "c2:     ");
}
