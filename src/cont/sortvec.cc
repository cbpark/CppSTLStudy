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
#include <string>
#include <vector>

int main() {
    // create a string vector
    // - initialized by all words from standard input
    std::vector<std::string> coll(
        (std::istream_iterator<std::string>(std::cin)),
        std::istream_iterator<std::string>());

    // sort elements
    std::sort(coll.begin(), coll.end());

    // print all elements
    std::unique_copy(coll.cbegin(), coll.cend(),
                     std::ostream_iterator<std::string>(std::cout, "\n"));
}
