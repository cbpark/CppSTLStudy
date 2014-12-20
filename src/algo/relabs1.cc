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
    std::vector<int> coll = {17, -3, 22, 13, 13, -9};
    PrintElements(coll, "coll:     ");

    // convert into relative values
    std::adjacent_difference(coll.cbegin(), coll.cend(),  // source
                             coll.begin());               // destination
    PrintElements(coll, "relative: ");

    // convert into absolute values
    std::partial_sum(coll.cbegin(), coll.cend(),  // source
                     coll.begin());               // destination
    PrintElements(coll, "absolute: ");
}
