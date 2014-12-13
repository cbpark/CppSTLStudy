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
#include <cstdlib>

bool AbsLess(int elem1, int elem2) {
    return std::abs(elem1) < std::abs(elem2);
}

int main() {
    std::deque<int> coll;

    InsertElements(coll, 2, 6);
    InsertElements(coll, -3, 6);

    PrintElements(coll);

    // process and print minimum and maximum
    std::cout << "minimum: "
              << *std::min_element(coll.cbegin(), coll.cend())
              << '\n';
    std::cout << "maximum: "
              << *std::max_element(coll.cbegin(), coll.cend())
              << '\n';

    // print min and max and their distance using minmax_element()
    auto mm = std::minmax_element(coll.cbegin(), coll.cend());
    std::cout << "min: " << *(mm.first) << '\n';   // print minimum
    std::cout << "max: " << *(mm.second) << '\n';  // print maximum
    std::cout << "distance: " << std::distance(mm.first, mm.second) << '\n';

    // process and print minimum and maximum of absolute values
    std::cout << "minimum of absolute values: "
              << *std::min_element(coll.cbegin(), coll.cend(),
                                   AbsLess)
              << '\n';
    std::cout << "maximum of absolute values: "
              << *std::max_element(coll.cbegin(), coll.cend(),
                                   AbsLess)
              << '\n';
}
