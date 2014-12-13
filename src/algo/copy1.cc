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
    std::vector<std::string> coll1 = {"Hello", "this", "is", "an", "exmaple"};
    std::list<std::string> coll2;

    // copy elements of coll1 into coll2
    // - use back inserter to insert instead of overwrite
    std::copy(coll1.cbegin(), coll1.cend(),
              std::back_inserter(coll2));

    // print elements of coll2
    // - copy elements to cout using an ostream iterator
    std::copy(coll2.cbegin(), coll2.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';

    // copy elements of coll1 into coll2 in reverse order
    // - now overwriting
    std::copy(coll1.crbegin(), coll1.crend(),
              coll2.begin());

    // print elements of coll2 again
    std::copy(coll2.cbegin(), coll2.cend(),
              std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << '\n';
}
