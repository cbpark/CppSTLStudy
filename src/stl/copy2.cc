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
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>

int main() {
    std::list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // copy the elements of coll1 into coll2 by appending them
    std::vector<int> coll2;
    std::copy(coll1.cbegin(), coll1.cend(),  // source
              std::back_inserter(coll2));    // destination

    for (const auto& elem : coll2) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // copy the elements of coll1 into coll3 by inserting them at the front
    // - reverses the order of the elements
    // - used only for containers that provide push_front():
    // -   deque, list, forward_list
    std::deque<int> coll3;
    std::copy(coll1.cbegin(), coll1.cend(),  // source
              std::front_inserter(coll3));   // destination

    for (const auto& elem : coll3) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // copy elements of coll1 into coll4
    // - only inserter that works for associative collections
    // -   all predefined containers except array and forward_list
    std::set<int> coll4;
    std::copy(coll1.cbegin(), coll1.cend(),          // source
              std::inserter(coll4, coll4.begin()));  // destination

    for (const auto& elem : coll4) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
