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
#include <vector>

int main() {
    // create ostream iterator for stream cout
    // - values are separated by a newline character
    std::ostream_iterator<int> int_writer(std::cout, "\n");

    // write elements with the usual iterator interface
    *int_writer = 42;
    int_writer++;
    *int_writer = 77;
    int_writer++;
    *int_writer = -5;

    // create collection with elements from 1 to 9
    std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // write all elements without any delimiter
    std::copy(coll.cbegin(), coll.cend(),
              std::ostream_iterator<int>(std::cout));
    std::cout << '\n';

    // write all elements with " < " as delimiter
    std::copy(coll.cbegin(), coll.cend(),
              std::ostream_iterator<int>(std::cout, " < "));
    std::cout << '\n';
}
