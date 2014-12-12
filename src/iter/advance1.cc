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

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    std::list<int>::iterator pos = coll.begin();

    // print actual element
    std::cout << *pos << '\n';

    // step three elements forward
    std::advance(pos, 3);

    // print actual element
    std::cout << *pos << '\n';

    // step one element backward
    std::advance(pos, -1);

    // print actual element
    std::cout << *pos << '\n';
}
