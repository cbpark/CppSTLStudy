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
    std::vector<int> c1 = {1, 2, 2, 4, 6, 7, 7, 9};
    std::deque<int>  c2 = {2, 2, 2, 3, 6, 6, 8, 9};

    // print source ranges
    std::cout << "c1:                         ";
    std::copy(c1.cbegin(), c1.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    std::cout << "c2:                         ";
    std::copy(c2.cbegin(), c2.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n\n";

    // sum the ranges by using merge()
    std::cout << "merge():                    ";
    std::merge(c1.cbegin(), c1.cend(),
               c2.cbegin(), c2.cend(),
               std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // unite the ranges by using set_union()
    std::cout << "set_union():                ";
    std::set_union(c1.cbegin(), c1.cend(),
                   c2.cbegin(), c2.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // intersect the ranges by using set_intersection()
    std::cout << "set_intersection():         ";
    std::set_intersection (c1.cbegin(), c1.cend(),
                           c2.cbegin(), c2.cend(),
                           std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // determine elements of first range without elements of second range
    // by using set_difference()
    std::cout << "set_difference():           ";
    std::set_difference (c1.cbegin(), c1.cend(),
                         c2.cbegin(), c2.cend(),
                         std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // determine difference the ranges with set_symmetric_difference()
    std::cout << "set_symmetric_difference(): ";
    std::set_symmetric_difference (c1.cbegin(), c1.cend(),
                                   c2.cbegin(), c2.cend(),
                                   std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
