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

    InsertElements(coll, 1, 9);
    PrintElements(coll);

    // check existence of element with value 5
    if (std::binary_search(coll.cbegin(), coll.cend(), 5)) {
        std::cout << "5 is present\n";
    } else {
        std::cout << "5 is not present\n";
    }

    // check existence of element with value 42
    if (std::binary_search(coll.cbegin(), coll.cend(), 42)) {
        std::cout << "42 is present\n";
    } else {
        std::cout << "42 is not present\n";
    }
}
