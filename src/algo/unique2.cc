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

bool DifferenceOne(int elem1, int elem2) {
    return elem1 + 1 == elem2 || elem1 - 1 == elem2;
}

int main() {
    // source data
    int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};

    // initialize coll with elements from source
    std::list<int> coll;
    std::copy(std::begin(source), std::end(source),  // source
              std::back_inserter(coll));             // destination
    PrintElements(coll);

    // print elements with consecutive duplicates removed
    std::unique_copy(coll.cbegin(), coll.cend(),                   // source
                     std::ostream_iterator<int>(std::cout, " "));  // destination
    std::cout << '\n';

    // print elements without consecutive entries that differ by one
    std::unique_copy(coll.cbegin(), coll.cend(),                  // source
                     std::ostream_iterator<int>(std::cout, " "),  // destination
                     DifferenceOne);                              // duplicates criterion
    std::cout << '\n';
}
