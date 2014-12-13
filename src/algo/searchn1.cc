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
    std::deque<int> coll;

    coll = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
    PrintElements(coll);

    // find three consecutive elements with value 7
    std::deque<int>::iterator pos;
    pos = std::search_n(coll.begin(), coll.end(),  // range
                        3,                         // count
                        7);                        // value

    // print result
    if (pos != coll.end()) {
        std::cout << "three consecutive elements with value 7 "
                  << "start with " << std::distance(coll.begin(), pos) + 1
                  << ". element\n";
    } else {
        std::cout << "no four consecutive elements with value 7 found\n";
    }

    // find four consecutive odd elements
    pos = std::search_n(coll.begin(), coll.end(),  // range
                        4,                         // count
                        0,                         // value
                        [] (int elem, int) {       // criterion
                            return elem % 2 == 1;
                        });

    // print result
    if (pos != coll.end()) {
        std::cout << "first four consecutive odd elements are: ";
        for (int i = 0; i < 4; ++i, ++pos) {
            std::cout << *pos << ' ';
        }
    } else {
        std::cout << "no four consecutive elements with value > 3 found";
    }
    std::cout << '\n';
}
