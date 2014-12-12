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
#include <iterator>
#include <vector>

int main() {
    std::vector<int> coll;

    // create back inserter for coll
    // - inconvenient way
    std::back_insert_iterator<std::vector<int>> iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;
    PrintElements(coll);

    // create back inserter and insert elements
    // - convenient way
    std::back_inserter(coll) = 44;
    std::back_inserter(coll) = 55;
    PrintElements(coll);

    // use back inserter to append all elements again
    // - reserve enough memory to avoid reallocation
    coll.reserve(2 * coll.size());
    std::copy(coll.begin(), coll.end(),   // source
              std::back_inserter(coll));  // destination
    PrintElements(coll);
}
