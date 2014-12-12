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
#include <list>
#include <set>

int main() {
    std::set<int> coll;

    // create insert inserter for coll
    // - inconvenient way
    std::insert_iterator<std::set<int>> iter(coll, coll.begin());

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    PrintElements(coll, "set:  ");

    // create inserter and insert elements
    // - convenient way
    std::inserter(coll, coll.end()) = 44;
    std::inserter(coll, coll.end()) = 55;

    PrintElements(coll, "set:  ");

    // use inserter to insert all elements into a list
    std::list<int> coll2;
    std::copy(coll.begin(), coll.end(),              // source
              std::inserter(coll2, coll2.begin()));  // destination

    PrintElements(coll2, "list: ");

    // use inserter to reinsert all elements into the list before
    // the second element
    std::copy(coll.begin(), coll.end(),                // source
              std::inserter(coll2, ++coll2.begin()));  // destination

    PrintElements(coll2, "list: ");
}
