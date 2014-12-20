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
    std::list<int> coll;

    InsertElements(coll, 1, 6);
    PrintElements(coll);

    // process sum of all products
    // (0 + 1*1 + 2*2 + 3*3 + 4*4 + 5*5 + 6*6)
    std::cout << "inner product: "
              << std::inner_product(coll.cbegin(), coll.cend(),  // first range
                                    coll.cbegin(),               // second range
                                    0)                           // initial value
              << '\n';

    // process sum of 1*6...6*1
    // (0 + 1*6 + 2*5 + 3*4 + 4*3 + 5*2 + 6*1)
    std::cout << "inner reverse product: "
              << std::inner_product(coll.cbegin(), coll.cend(),  // first range
                                    coll.crbegin(),              // second range
                                    0)                           // initial value
              << '\n';

    // process product of all sums
    std::cout << "product of sums: "
              << std::inner_product(coll.cbegin(), coll.cend(),  // first range
                                    coll.cbegin(),               // second range
                                    1,                           // initial value
                                    std::multiplies<int>(),      // outer operation
                                    std::plus<int>())            // inner operation
              << '\n';
}
