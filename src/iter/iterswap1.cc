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
#include "print.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main() {
    std::list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    PrintElements(coll);

    // swap first and second value
    std::iter_swap(coll.begin(), std::next(coll.begin()));

    PrintElements(coll);

    // swap first and last value
    std::iter_swap(coll.begin(), std::prev(coll.end()));

    PrintElements(coll);
}
