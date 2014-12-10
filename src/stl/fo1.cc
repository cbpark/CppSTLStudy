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
#include "print.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>

int main() {
    std::deque<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19};

    PrintElements(coll, "initialized: ");

    // negate all values in coll
    std::transform(coll.cbegin(), coll.cend(),  // source
                   coll.begin(),                // destination
                   std::negate<int>());         // operation

    PrintElements(coll, "negated:     ");

    // square all values in coll
    std::transform(coll.cbegin(), coll.cend(),  // first source
                   coll.cbegin(),               // second source
                   coll.begin(),                // destination
                   std::multiplies<int>());     // operation
    PrintElements(coll, "sqquared:    ");
}
