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
    std::vector<int> coll;
    int num;
    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll: ");

    // count elements with value 4
    num = std::count(coll.cbegin(), coll.cend(),  // range
                     4);                          // value
    std::cout << "number of elements equal to 4:      " << num << '\n';

    // count elements with even value
    num = std::count_if(coll.cbegin(), coll.cend(),  // range
                        [] (int elem) {              // criterion
                            return elem % 2 == 0;
                        });
    std::cout << "number of elements with even value: " << num << '\n';

    // count elements that are greater than value 4
    num = std::count_if(coll.cbegin(), coll.cend(),  // range
                        [] (int elem) {              // criterion
                            return elem > 4;
                        });
    std::cout << "number of elements greater than 4:  " << num << '\n';
}
