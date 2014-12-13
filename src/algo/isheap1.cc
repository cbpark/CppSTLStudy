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
    std::vector<int> coll1 = {9, 8, 7, 7, 7, 5, 4, 2, 1};
    std::vector<int> coll2 = {5, 3, 2, 1, 4, 7, 9, 8, 6};
    PrintElements(coll1, "coll1: ");
    PrintElements(coll2, "coll2: ");

    // check whether theh collections are heaps
    std::cout << std::boolalpha << "coll1 is heap: "
              << std::is_heap(coll1.cbegin(), coll1.cend()) << '\n';
    std::cout << "coll2 is heap: "
              << std::is_heap(coll2.cbegin(), coll2.cend()) << '\n';

    // print the first element that is not a heap in coll2
    auto pos = std::is_heap_until(coll2.cbegin(), coll2.cend());
    if (pos != coll2.end()) {
        std::cout << "first non-heap element: " << *pos << '\n';
    }
}
