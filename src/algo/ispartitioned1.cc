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
    std::vector<int> coll = {5, 3, 9, 1, 3, 4, 8, 2, 6};
    PrintElements(coll, "coll: ");

    // define predicate: check whether element is odd
    auto is_odd = [] (int elem) {
        return elem % 2 == 1;
    };

    // check whether coll is partitioned in odd and even elements
    if (std::is_partitioned(coll.cbegin(), coll.cend(), is_odd)) {
        std::cout << "coll is partitioned\n";

        // find first even element
        auto pos = std::partition_point(coll.cbegin(), coll.cend(), is_odd);
        std::cout << "first even element: " << *pos << '\n';
    } else {
        std::cout << "coll is not partitioned\n";
    }
}
