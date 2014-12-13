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
    std::vector<int> coll;
    std::list<int> searchcoll;

    InsertElements(coll, 1, 11);
    InsertElements(searchcoll, 3, 5);

    PrintElements(coll,    "coll:    ");
    PrintElements(searchcoll, "searchcoll: ");

    // search first occurrence of searchcoll in coll
    std::vector<int>::iterator pos;
    pos = std::find_first_of(coll.begin(), coll.end(),
                             searchcoll.begin(),
                             searchcoll.end());
    std::cout << "first element of searchcoll in coll is element "
              << std::distance(coll.begin(), pos) + 1
              << '\n';

    // search last occurrence of an element of searchcoll in coll
    std::vector<int>::reverse_iterator rpos;
    rpos = std::find_first_of(coll.rbegin(), coll.rend(),
                              searchcoll.begin(),
                              searchcoll.end());
    std::cout << "last element of searchcoll in coll is element "
              << std::distance(coll.begin(), rpos.base())
              << '\n';
}
