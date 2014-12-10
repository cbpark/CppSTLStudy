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
    std::vector<std::string> coll;

    // read all words from the standard input
    // - source: all strings until end-of-file (or error)
    // - destination: coll (inserting)
    std::copy(std::istream_iterator<std::string>(std::cin),  // start of source
              std::istream_iterator<std::string>(),          // end of source
              std::back_inserter(coll));                     // destination

    // sort elements
    std::sort(coll.begin(), coll.end());

    // print all elements without duplicates
    // - source: coll
    // - destination: standard output (with newline between elements)
    std::unique_copy(
        coll.cbegin(), coll.cend(),                            // source
        std::ostream_iterator<std::string>(std::cout, "\n"));  // destination
}
