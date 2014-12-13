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

// checks whether an element is even or odd
bool CheckEven(int elem, bool even) {
    if (even) {
        return elem % 2 == 0;
    } else {
        return elem % 2 == 1;
    }
}

int main() {
    std::vector<int> coll;

    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll: ");

    // arguments for CheckEven()
    // - check for: ``even odd even''
    bool check_even_args[3] = {true, false, true};

    // search first subrange in coll
    std::vector<int>::iterator pos;
    pos = std::search(coll.begin(), coll.end(),              // range
                      check_even_args, check_even_args + 3,  // subrange values
                      CheckEven);                            // subrange criterion

    // loop while subrange found
    while (pos != coll.end()) {
        // print position of first element
        std::cout << "subrange found starting with element "
                  << distance(coll.begin(), pos) + 1
                  << '\n';

        // search next subrange in coll
        pos = search (++pos, coll.end(),                     // range
                      check_even_args, check_even_args + 3,  // subrange values
                      CheckEven);                            // subrange criterion
    }
}
