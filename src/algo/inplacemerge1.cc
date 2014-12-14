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

    // insert two sorted sequences
    InsertElements(coll, 1, 7);
    InsertElements(coll, 1, 8);
    PrintElements(coll);

    // find beginning of second part (element after 7)
    std::list<int>::iterator pos;
    pos = std::find(coll.begin(), coll.end(),  // range
                    7);                        // value
    ++pos;

    // merge into one sorted range
    std::inplace_merge(coll.begin(), pos, coll.end());

    PrintElements(coll);
}
