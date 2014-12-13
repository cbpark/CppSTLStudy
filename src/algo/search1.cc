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
    std::deque<int> coll;
    std::list<int> subcoll;

    InsertElements(coll, 1, 7);
    InsertElements(coll, 1, 7);
    InsertElements(subcoll, 3, 6);

    PrintElements(coll,    "coll:    ");
    PrintElements(subcoll, "subcoll: ");

    // search first occurrence of subcoll in coll
    std::deque<int>::iterator pos;
    pos = std::search(coll.begin(), coll.end(),         // range
                      subcoll.begin(), subcoll.end());  // subrange

    // loop while subcoll found as subrange of coll
    while (pos != coll.end()) {
        // print position of first element
        std::cout << "subcoll found starting with element "
                  << std::distance(coll.begin(), pos) + 1
                  << '\n';

        // search next occurrence of subcoll
        ++pos;
        pos = search(pos, coll.end(),                  // range
                     subcoll.begin(), subcoll.end());  // subrange
    }
}
