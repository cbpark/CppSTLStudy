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
#include <iostream>
#include <list>

template <typename T>
void PrintElements(const T& coll) {
    for (const auto& elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::list<char> coll;  // list container for character elements

    // append elements from 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c) {
        coll.push_back(c);
    }

    // print all elements
    // - use range-based for loop
    for (auto elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
