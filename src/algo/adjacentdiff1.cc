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

    InsertElements(coll, 1, 6);
    PrintElements(coll);

    // print all differences between elements
    std::adjacent_difference(coll.cbegin(), coll.cend(),                   // source
                             std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';

    // print all sums with the predecessors
    std::adjacent_difference(coll.cbegin(), coll.cend(),                  // source
                             std::ostream_iterator<int>(std::cout, " "),  // destination
                             std::plus<int>());                           // operation
    std::cout << '\n';

    // print all products between elements
    std::adjacent_difference(coll.cbegin(), coll.cend(),                  // source
                             std::ostream_iterator<int>(std::cout, " "),  // destination
                             std::multiplies<int>());                     // operation
    std::cout << '\n';
}
