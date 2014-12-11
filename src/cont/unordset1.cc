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
#include <numeric>
#include <unordered_set>

int main() {
    // create and initialize unordered set
    std::unordered_set<int> coll = {1, 2, 3, 5, 7, 11, 13, 17, 19, 77};

    // print elements
    // - elements are in arbitrary order
    PrintElements(coll);

    // insert some additional elements
    // - might cause rehashing and create different order
    coll.insert({-7, 17, 33, -11, 17, 19, 1, 13});
    PrintElements(coll);

    // remove element with specific value
    coll.erase(33);

    // insert sum of all existing values
    coll.insert(std::accumulate(coll.begin(), coll.end(), 0));
    PrintElements(coll);

    // check if value 19 is in the set
    if (coll.find(19) != coll.end()) {
        std::cout << "19 is available\n";
    }

    // remove all negative numbers
    std::unordered_set<int>::iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ) {
        if (*pos < 0) {
            pos = coll.erase(pos);
        } else {
            ++pos;
        }
    }
    PrintElements(coll);
}
