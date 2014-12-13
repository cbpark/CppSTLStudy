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

void PrintCollection(const std::list<int>& l) {
    PrintElements(l);
}

bool LessForCollection(const std::list<int>& l1, const std::list<int>& l2) {
    return std::lexicographical_compare(l1.cbegin(), l1.cend(),
                                        l2.cbegin(), l2.cend());
}

int main() {
    std::list<int> c1, c2, c3, c4;

    // fill all collection with the same starting values
    InsertElements(c1, 1, 5);
    c4 = c3 = c2 = c1;

    // and now some differences
    c1.push_back(7);
    c3.push_back(2);
    c3.push_back(0);
    c4.push_back(2);

    // create collection of collections
    std::vector<std::list<int>> cc;
    cc.insert(cc.begin(), {c1, c2, c3, c4, c3, c1, c4, c2});

    // print all collections
    std::for_each(cc.cbegin(), cc.cend(), PrintCollection);
    std::cout << '\n';

    // sort collection lexicographically
    std::sort(cc.begin(), cc.end(), LessForCollection);

    // print all collections again
    std::for_each(cc.cbegin(), cc.cend(), PrintCollection);
}
