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
    std::vector<int> coll1 = {1, 2, 3, 4, 5, 6};
    std::list<int>   coll2 = {1, 2, 4, 8, 16, 3};

    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");

    // find first mismatch
    auto values = std::mismatch(coll1.cbegin(), coll1.cend(),
                                coll2.cbegin());
    if (values.first == coll1.end()) {
        std::cout << "no mismatch\n";
    } else {
        std::cout << "first mismatch: "
                  << *values.first << " and "
                  << *values.second << '\n';
    }

    // find first position where the element of coll1 is not
    // less than the second corresponding element of coll2
    values = std::mismatch(coll1.cbegin(), coll1.cend(),
                           coll2.cbegin(),
                           std::less_equal<int>());
    if (values.first == coll1.end()) {
        std::cout << "always less-or-equal\n";
    } else {
        std::cout << "not less-or-equal: "
                  << *values.first << " and "
                  << *values.second << '\n';
    }
}
