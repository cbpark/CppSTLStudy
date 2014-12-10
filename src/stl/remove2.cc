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
#include <iostream>
#include <iterator>
#include <list>

int main() {
    std::list<int> coll;

    // insert elements from 6 to 1 and 1 to 6
    for (int i = 1; i <= 6; ++i) {
        coll.push_front(i);
        coll.push_back(i);
    }

    // print all elements of the collection
    std::copy(coll.cbegin(), coll.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // remove all elements with value 3
    // - retain new end
    std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 3);

    // print resulting elements of the collection
    std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // print number of removed elements
    std::cout << "number of remvoed elements: "
              << std::distance(end, coll.end()) << '\n';

    // remove ``removed'' elements
    coll.erase(end, coll.end());

    // print all elements of the modified collection
    std::copy(coll.cbegin(), coll.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
