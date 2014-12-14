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
    std::vector<int> search;

    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll: ");

    search.push_back(3);
    search.push_back(4);
    search.push_back(7);
    PrintElements(search, "search: ");

    // check whether all elements in search are also in coll
    if (includes(coll.cbegin(), coll.cend(),
                 search.cbegin(), search.cend())) {
        std::cout << "all elements of search are also in coll\n";
    } else {
        std::cout << "not all elements of search are also in coll\n";
    }
}
