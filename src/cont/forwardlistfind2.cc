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
#include "findbefore.h"
#include "print.h"
#include <forward_list>

int main() {
    std::forward_list<int> list = {1, 2, 3, 4, 5, 97, 98, 99};

    // find the position before the first even element
    auto pos_before = find_before_if(list.before_begin(), list.end(),
                                     [] (int i) {
                                         return i % 2 == 0;
                                     });

    // and insert a new element in front of the first even element
    list.insert_after(pos_before, 42);
    PrintElements(list);
}
