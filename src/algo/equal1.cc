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

bool BothEvenOrOdd(int elem1, int elem2) {
    return elem1 % 2 == elem2 % 2;
}

int main() {
    std::vector<int> coll1;
    std::list<int> coll2;

    InsertElements(coll1, 1, 7);
    InsertElements(coll1, 3, 9);

    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");

    // check whether both collections are equal
    if (std::equal(coll1.begin(), coll1.end(),  // first range
                   coll2.begin())) {            // second range
        std::cout << "coll1 == coll2\n";
    } else {
        std::cout << "coll1 != coll2\n";
    }

    // check for corresponding even and odd elements
    if (std::equal(coll1.begin(), coll1.end(),
                   coll2.begin(),
                   BothEvenOrOdd)) {
        std::cout << "even and odd elements correspond\n";
    } else {
        std::cout << "even and odd elements do not correspond\n";
    }
}
