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

    // extract the four lowest elements
    std::nth_element(coll.begin(),      // beginning of range
                     coll.begin() + 3,  // element that should be sorted correctly
                     coll.end());       // end of range

    // print them
    std::cout << "the four lowest elements are:  ";
    std::copy(coll.cbegin(), coll.cbegin() + 4,
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // extract the four highest elements
    std::nth_element(coll.begin(),    // beginning of range
                     coll.end() - 4,  // elements that should be sorted correctly
                     coll.end());     // end of range

    // print them
    std::cout << "the four highest elements are: ";
    std::copy(coll.cend() - 4, coll.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // extract the four highest elements (second version)
    std::nth_element(coll.begin(),          // beginning of range
                     coll.begin() + 3,      // element that should be sorted correctly
                     coll.end(),            // end of range
                     std::greater<int>());  // sorting criterion

    // print them
    std::cout << "the four highest elements are: ";
    std::copy(coll.cbegin(), coll.cbegin() + 4,
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
