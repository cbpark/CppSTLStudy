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
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

int main() {
    // create array with 10 ints
    std::array<int, 10> a = {{11, 22, 33, 44}};

    PrintElements(a);

    // modifying last two elements
    a.back() = 9999999;
    a[a.size() - 2] = 42;
    PrintElements(a);

    // process sum of all elements
    std::cout << "sum: "
              << std::accumulate(a.begin(), a.end(), 0)
              << '\n';

    // negate all elements
    std::transform(a.begin(), a.end(),   // source
                   a.begin(),            // destination
                   std::negate<int>());  // operation
    PrintElements(a);
}
