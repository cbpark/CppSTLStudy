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

    InsertElements(coll, 3, 7);
    InsertElements(coll, 2, 6);
    InsertElements(coll, 1, 5);
    PrintElements(coll);

    // sort until the first five elements are sorted
    std::partial_sort(coll.begin(),      // beginning of the range
                      coll.begin() + 5,  // end of sorted range
                      coll.end());       // end of full range
    PrintElements(coll);

    // sort inversely until the first five elements are sorted
    std::partial_sort(coll.begin(),          // beginning of the range
                      coll.begin() + 5,      // end of sorted range
                      coll.end(),            // end of full range
                      std::greater<int>());  // sorting criterion
    PrintElements(coll);

    // sort all elements
    std::partial_sort(coll.begin(),  // beginning of the range
                      coll.end(),    // end of sorted range
                      coll.end());   // end of full range
    PrintElements(coll);
}
