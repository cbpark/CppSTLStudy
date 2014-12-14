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
    std::vector<int> coll = {1, 6, 33, 7, 22, 4, 11, 33, 2, 7, 0, 42, 5};
    PrintElements(coll, "coll: ");

    // destination collections
    std::vector<int> even_coll;
    std::vector<int> odd_coll;

    // copy all elements partitioned accordingly into even and odd elements
    std::partition_copy(coll.cbegin(), coll.cend(),     // source range
                        std::back_inserter(even_coll),  // destination of even elements
                        std::back_inserter(odd_coll),   // destination of odd elements
                        [] (int elem) {                 // predicate: check for even numbers
                            return elem % 2 == 0;
                        });

    PrintElements(even_coll, "even_coll: ");
    PrintElements(odd_coll, "odd_coll: ");
}
