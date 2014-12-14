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

    InsertElements(coll, 1, 9);
    InsertElements(coll, 1, 9);
    coll.sort();
    PrintElements(coll);

    // print first and last position 5 could get inserted
    std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator>
        range;
    range = std::equal_range(coll.cbegin(), coll.cend(),
                             5);

    std::cout << "5 could get position "
              << std::distance(coll.cbegin(), range.first) + 1
              << " up to "
              << std::distance(coll.cbegin(), range.second) + 1
              << " without breaking the sorting\n";
}
