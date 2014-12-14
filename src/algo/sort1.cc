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

    InsertElements(coll, 1, 9);
    InsertElements(coll, 1, 9);

    PrintElements(coll, "on entry: ");

    // sort elements
    std::sort(coll.begin(), coll.end());

    PrintElements(coll, "sorted:   ");

    // sorted reverse
    std::sort(coll.begin(), coll.end(),  // range
              std::greater<int>());      // sorting criterion

    PrintElements(coll, "sorted >: ");
}
