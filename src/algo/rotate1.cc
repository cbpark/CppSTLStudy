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
    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:      ");

    // rotate one element to the left
    std::rotate(coll.begin(),      // beginning of range
                coll.begin() + 1,  // new first element
                coll.end());       // end of range
    PrintElements(coll, "one left:  ");

    // rotate two lements to the right
    std::rotate(coll.begin(),    // beginning of range
                coll.end() - 2,  // new first element
                coll.end());     // end of range
    PrintElements(coll, "two right: ");

    // rotate so that element with value 4 is the beginning
    std::rotate(coll.begin(),                            // beginning of range
                std::find(coll.begin(), coll.end(), 4),  // new first element
                coll.end());                             // end of range
    PrintElements(coll, "4 first:   ");
}
