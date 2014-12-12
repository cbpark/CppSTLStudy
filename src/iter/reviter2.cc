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
#include <vector>

int main() {
    // create list with elements from 1 to 9
    std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // find position of element with value 5
    std::vector<int>::const_iterator pos;
    pos = std::find(coll.cbegin(), coll.cend(), 5);

    // print value to which iterator pos refers
    std::cout << "pos:  " << *pos << '\n';

    // convert iterator to reverse iterator rpos
    std::vector<int>::const_reverse_iterator rpos(pos);

    // print value to which reverse iterator rpos refers
    std::cout << "rpos: " << *rpos << '\n';
}
