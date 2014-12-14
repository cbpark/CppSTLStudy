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
    std::vector<int> coll1;
    std::vector<int> coll2;

    InsertElements(coll1, 1, 9);
    InsertElements(coll2, 1, 9);
    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");
    std::cout << '\n';

    // move all even elements to the front
    std::vector<int>::iterator pos1, pos2;
    pos1 = std::partition(coll1.begin(), coll1.end(),  // range
                          [] (int elem) {              // criterion
                              return elem % 2 == 0;
                          });
    pos2 = std::stable_partition(coll2.begin(), coll2.end(),  // range
                                 [] (int elem) {              // criterion
                                     return elem % 2 == 0;
                                 });

    // print collections and first odd element
    PrintElements(coll1, "coll1: ");
    std::cout << "first odd element: " << *pos1 << '\n';
    PrintElements(coll2, "coll2: ");
    std::cout << "first odd element: " << *pos2 << '\n';
}
