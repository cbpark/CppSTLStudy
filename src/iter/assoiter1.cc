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
#include "assoiter.h"
#include "print.h"
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    std::unordered_set<int> coll;

    // create inserter for coll
    // - inconvenient way
    AssoInsertIterator<decltype(coll)> iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    PrintElements(coll);

    // create inserter for coll and insert elements
    // - convenient way
    asso_inserter(coll) = 44;
    asso_inserter(coll) = 55;

    PrintElements(coll);

    // use inserter with an algorithm
    std::vector<int> vals = {33, 67, -4, 13, 5, 2};
    std::copy (vals.begin(), vals.end(),  // source
               asso_inserter(coll));      // destination

    PrintElements(coll);
}
