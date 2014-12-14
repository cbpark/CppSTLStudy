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
    std::set<int> coll;
    InsertElements(coll, 1, 9);
    PrintElements(coll);

    // print elements rotated one element to the left
    std::set<int>::const_iterator pos = std::next(coll.cbegin());
    std::rotate_copy(coll.cbegin(),                                // beginning of source
                     pos,                                          // new first element
                     coll.cend(),                                  // end of source
                     std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';

    // print elements rotated two elements to the right
    pos = coll.cend();
    std::advance(pos, -2);
    std::rotate_copy(coll.cbegin(),                                // beginning of source
                     pos,                                          // new first element
                     coll.cend(),                                  // end of source
                     std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';

    // print elements rotated so that element with value 4 is the beginning
    std::rotate_copy(coll.cbegin(),                                // beginning of source
                     coll.find(4),                                 // new first element
                     coll.cend(),                                  // end of source
                     std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';
}
