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

    InsertElements(coll, 3, 7);
    InsertElements(coll, 5, 9);
    InsertElements(coll, 1, 4);

    PrintElements(coll, "on entry:          ");

    // convert collections into a heap
    std::make_heap(coll.begin(), coll.end());

    PrintElements(coll, "after make_heap(): ");

    // pop next element out of the heap
    std::pop_heap(coll.begin(), coll.end());
    coll.pop_back();

    PrintElements(coll, "after pop_heap():  ");

    // push new element into the heap
    coll.push_back(17);
    std::push_heap(coll.begin(), coll.end());

    PrintElements(coll, "after push_heap(): ");

    // convert heap into a sorted collection
    // - NOTE: after the call it is no longer a heap
    std::sort_heap(coll.begin(), coll.end());

    PrintElements(coll, "after sort_heap(): ");
}
