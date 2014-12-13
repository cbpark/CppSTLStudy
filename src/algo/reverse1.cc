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
    PrintElements(coll, "coll: ");

    // reverse order of elements
    std::reverse(coll.begin(), coll.end());
    PrintElements(coll, "coll: ");

    // reverse order from second to last element but one
    std::reverse(coll.begin() + 1, coll.end() - 1);
    PrintElements(coll, "coll: ");

    // print all of them in reverse order
    std::reverse_copy(coll.cbegin(), coll.cend(),                   // source
                      std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';
}
