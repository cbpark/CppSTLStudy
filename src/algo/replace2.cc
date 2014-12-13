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

using std::placeholders::_1;

int main() {
    std::list<int> coll;

    InsertElements(coll, 2, 6);
    InsertElements(coll, 4, 9);
    PrintElements(coll);

    // print all element with value 5 replaced with 55
    std::replace_copy(coll.cbegin(), coll.cend(),                  // source
                      std::ostream_iterator<int>(std::cout, " "),  // destination
                      5,                                           // old value
                      55);                                         // new value
    std::cout << '\n';

    // print all element with value less than 5 replaced with 42
    std::replace_copy_if(coll.cbegin(), coll.cend(),                  // source
                         std::ostream_iterator<int>(std::cout, " "),  // destination
                         std::bind(std::less<int>(), _1, 5),          // replacement criterion
                         42);                                         // new value
    std::cout << '\n';

    // print each element while each odd element is replaced with 0
    std::replace_copy_if(coll.cbegin(), coll.cend(),                  // source
                         std::ostream_iterator<int>(std::cout, " "),  // destination
                         [] (int elem) {                              // replacement criterion
                             return elem % 2 == 1;
                         },
                         0);                                          // new value
    std::cout << '\n';
}
