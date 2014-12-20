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
    std::vector<int> coll;

    InsertElements(coll, 1, 9);
    PrintElements(coll);

    // process sum of elements
    std::cout << "sum: "
              << std::accumulate(coll.cbegin(), coll.cend(),  // range
                                 0)                           // initial value
              << '\n';

    // process sum of elements less 100
    std::cout << "sum: "
              << std::accumulate(coll.cbegin(), coll.cend(),  // range
                                 -100)                        // initial value
              << '\n';

    // process sum of elements
    std::cout << "product: "
              << std::accumulate(coll.cbegin(), coll.cend(),  // range
                                 1,                           // initial value
                                 std::multiplies<int>())      // operation
              << '\n';

    // process sum of elements (use 0 as initial value)
    std::cout << "product: "
              << std::accumulate(coll.cbegin(), coll.cend(),  // range
                                 0,                           // initial value
                                 std::multiplies<int>())      // operation
              << '\n';
}
