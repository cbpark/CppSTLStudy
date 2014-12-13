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
    std::list<int> coll1;

    InsertElements(coll1, 1, 6);
    InsertElements(coll1, 1, 9);
    PrintElements(coll1);

    // rprint elements without those having the value 3
    std::remove_copy(coll1.cbegin(), coll1.cend(),                // source
                     std::ostream_iterator<int>(std::cout, " "),  // destination
                     3);                                          // removed value
    std::cout << '\n';

    // print elements without those having a value greater than 4
    std::remove_copy_if(coll1.cbegin(), coll1.cend(),                // source
                        std::ostream_iterator<int>(std::cout, " "),  // destination
                        [] (int elem) {  // criterion for elements NOT copied
                            return elem > 4;
                        });
    std::cout << '\n';

    // copy all elements not less than 4 into a multiset
    std::multiset<int> coll2;
    std::remove_copy_if(coll1.cbegin(), coll1.cend(),         // source
                        std::inserter(coll2, coll2.end()),    // destination
                        std::bind(std::less<int>(), _1, 4));  // elements NOT copied
    PrintElements(coll2);
}
