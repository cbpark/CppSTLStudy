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

    InsertElements(coll, 2, 7);
    InsertElements(coll, 4, 9);
    PrintElements(coll, "coll: ");

    // replace all elements with value 6 with 42
    std::replace(coll.begin(), coll.end(),  // range
                 6,                         // old value
                 42);                       // new value
    PrintElements(coll, "coll: ");

    // replace all elements with value less than 5 with 0
    std::replace_if(coll.begin(), coll.end(),  // range
                    [] (int elem) {            // criterion for replacement
                        return elem < 5;
                    },
                    0);                        // new value
    PrintElements(coll, "coll: ");
}
