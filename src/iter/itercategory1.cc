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
#include <vector>

int main() {
    std::vector<int> coll;

    // insert elements from -3 to 9
    for (int i = -3; i <= 9; ++i) {
        coll.push_back(i);
    }

    // print number of elements by processing the distance between
    // beginning and end
    // - NOTE: uses operator- for iterators
    std::cout << "number/distance: " << coll.end() - coll.begin() << '\n';

    // print all elements
    // - NOTE: uses operator< instead of operator!=
    std::vector<int>::iterator pos;
    for (pos = coll.begin(); pos < coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << '\n';

    // print all elements
    // - NOTE: uses operator[] instead of operator*
    for (unsigned int i = 0; i < coll.size(); ++i) {
        std::cout << coll.begin()[i] << ' ';
    }
    std::cout << '\n';

    // print every second element
    // - NOTE: uses operator+=
    for (pos = coll.begin(); pos < coll.end() - 1; pos += 2) {
        std::cout << *pos << ' ';
    }
    std::cout << '\n';
}
