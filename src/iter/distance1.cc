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
#include <list>

int main() {
    std::list<int> coll;

    // insert elements from -3 to 9
    for (int i = -3; i <= 9; ++i) {
        coll.push_back(i);
    }

    // search element with value 5
    std::list<int>::iterator pos;
    pos = std::find(coll.begin(), coll.end(),  // range
                    5);                        // value

    if (pos != coll.end()) {
        // process and print difference from the beginning
        std::cout << "difference between beginning and 5: "
                  << std::distance(coll.begin(), pos) << '\n';
    } else {
        std::cout << "5 not found\n";
    }
}
