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

    PrintElements(coll, "coll: ");

    // find first element with value 4
    std::list<int>::iterator pos1;
    pos1 = std::find(coll.begin(), coll.end(),  // range
                     4);                        // value

    // find second element with value 4
    std::list<int>::iterator pos2;
    if (pos1 != coll.end()) {
        pos2 = std::find(++pos1, coll.end(),  // range
                         4);                  // value
    }

    // print all elements with first to second 4 (both included)
    // - note: now we need the position of the first 4 again (if any)
    if (pos1 != coll.end() && pos2 != coll.end()) {
        std::copy(--pos1, ++pos2,
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
}
