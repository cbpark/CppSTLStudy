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
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <set>

using std::bind;
using std::placeholders::_1;

int main() {
    std::set<int, std::greater<int>> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> coll2;

    // Note: due to the sorting criterion greater<>() elements have
    // reverse order
    PrintElements(coll1, "initialized: ");

    // transform all elements into coll2 by multiplying them with 10
    std::transform(coll1.cbegin(), coll1.cend(),
                   std::back_inserter(coll2),
                   bind(std::multiplies<int>(), _1, 10));
    PrintElements(coll2, "transformed: ");

    // replace value equal to 70 with 42
    std::replace_if(coll2.begin(), coll2.end(),
                    bind(std::equal_to<int>(), _1, 70),
                    42);
    PrintElements(coll2, "transformed: ");

    // remove all elements with values between 50 and 80
    coll2.erase(std::remove_if(coll2.begin(), coll2.end(),
                               bind(std::logical_and<bool>(),
                                         bind(std::greater_equal<int>(), _1, 50),
                                         bind(std::less_equal<int>(), _1, 80))),
                coll2.end());
    PrintElements(coll2, "removed:     ");
}
