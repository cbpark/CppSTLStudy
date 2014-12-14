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
    std::list<int> coll1;
    std::set<int> coll2;

    // fill both collections with some sorted elements
    InsertElements(coll1, 1, 6);
    InsertElements(coll2, 3, 8);

    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");

    // print merged sequence
    std::cout << "merged: ";
    std::merge(coll1.cbegin(), coll1.cend(),
               coll2.cbegin(), coll2.cend(),
               std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
