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
    std::vector<int> coll1;
    std::list<int> coll2;

    InsertElements(coll1, 1, 9);
    PrintElements(coll1, "coll1:   ");

    // square each element
    std::transform(coll1.cbegin(), coll1.cend(),
                   coll1.cbegin(),
                   coll1.begin(),
                   std::multiplies<int>());
    PrintElements(coll1, "squared: ");

    // add each element trasversed forward with each element traversed backward
    // and insert result into coll2
    std::transform(coll1.cbegin(), coll1.cend(),
                   coll1.crbegin(),
                   std::back_inserter(coll2),
                   std::plus<int>());
    PrintElements(coll2, "coll2:   ");

    // print differences of two corresponding elements
    std::cout << "diff:    ";
    std::transform(coll1.cbegin(), coll1.cend(),
                   coll2.cbegin(),
                   std::ostream_iterator<int>(std::cout, " "),
                   std::minus<int>());
    std::cout << '\n';
}
