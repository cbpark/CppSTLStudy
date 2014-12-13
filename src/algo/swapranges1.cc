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
    std::vector<int> coll1;
    std::deque<int> coll2;

    InsertElements(coll1, 1, 9);
    InsertElements(coll2, 11, 23);
    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");

    // swap elements of coll1 with corresponding elements of coll2
    std::deque<int>::iterator pos;
    pos = std::swap_ranges(coll1.begin(), coll1.end(), coll2.begin());

    PrintElements(coll1, "\ncoll1: ");
    PrintElements(coll2, "coll2: ");
    if (pos != coll2.end()) {
        std::cout << "first element not modified "
                  << *pos << '\n';
    }

    // mirror first three with last elements in coll2
    std::swap_ranges(coll2.begin(), coll2.begin() + 3, coll2.rbegin());

    PrintElements(coll2, "\ncoll2: ");
}
