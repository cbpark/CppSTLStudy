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

int main() {
    std::list<int> coll;

    // create front inserter for coll
    // - inconvenient way
    std::front_insert_iterator<std::list<int>> iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;
    iter++;
    *iter = 2;
    iter++;
    *iter = 3;

    PrintElements(coll);

    // create front inserter and insert elements
    // - convenient way
    std::front_inserter(coll) = 44;
    std::front_inserter(coll) = 55;

    PrintElements(coll);

    // use front inserter to append all elements again
    std::copy(coll.begin(), coll.end(),    // source
              std::front_inserter(coll));  // destination

    PrintElements(coll);
}
