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
#include <iterator>
#include <list>

void print(int elem) {
    std::cout << elem << ' ';
}

int main() {
    // create list with elements from 1 to 9
    std::list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // print all elements in normal order
    std::for_each(coll.begin(), coll.end(),  // range
                  print);                    // operation
    std::cout << '\n';

    // print all elements in reverse order
    std::for_each(coll.rbegin(), coll.rend(),  // range
                  print);                      // operation
    std::cout << '\n';
}
