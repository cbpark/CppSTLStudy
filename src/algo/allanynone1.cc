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
    std::vector<int> coll;
    std::vector<int>::iterator pos;

    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll: ");

    // define an object for the predicate (using a lambda)
    auto is_even = [] (int elem) {
        return elem % 2 == 0;
    };

    // print whether all, any, or none of the elements are/is even
    std::cout << std::boolalpha << "all even?: "
              << std::all_of(coll.cbegin(), coll.cend(), is_even) << '\n';
    std::cout << "any even?: "
              << std::any_of(coll.cbegin(), coll.cend(), is_even) << '\n';
    std::cout << "none even?: "
              << std::none_of(coll.cbegin(), coll.cend(), is_even) << '\n';
}
