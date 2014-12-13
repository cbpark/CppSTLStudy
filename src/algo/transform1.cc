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

using std::placeholders::_1;

int main() {
    std::vector<int> coll1;
    std::list<int> coll2;

    InsertElements(coll1, 1, 9);
    PrintElements(coll1, "coll1:   ");

    // negate all elements in coll1
    std::transform(coll1.cbegin(), coll1.cend(),
                   coll1.begin(),
                   std::negate<int>());
    PrintElements(coll1, "negated: ");

    // transform elements of coll1 into coll2 with ten times their value
    std::transform(coll1.cbegin(), coll1.cend(),
                   std::back_inserter(coll2),
                   std::bind(std::multiplies<int>(), _1, 10));
    PrintElements(coll2, "coll2:   ");

    // print coll2 negatively and in reverse order
    std::transform(coll2.crbegin(), coll2.crend(),
                   std::ostream_iterator<int>(std::cout, " "),
                   [] (int elem) {
                       return -elem;
                   });
    std::cout << '\n';
}
