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
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>

int main() {
    int coll[] = {5, 6, 2, 4, 1, 3};

    // square all elements
    std::transform(coll, coll + 6,           // first source
                   coll,                     // second source
                   coll,                     // destination
                   std::multiplies<int>());  // operation

    // sort beginning with the second element
    std::sort(coll + 1, coll + 6);

    // print all elements
    std::copy(coll, coll + 6, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
