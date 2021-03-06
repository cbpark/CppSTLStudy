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
    std::vector<int> coll;  // vector container for integer elements

    // append elements with values 1 to 6
    for (int i = 1; i <= 6; ++i) {
        coll.push_back(i);
    }

    // print all elements followed by a space
    for (int i = 0; i < coll.size(); ++i) {
        std::cout << coll[i] << ' ';
    }
    std::cout << '\n';
}
