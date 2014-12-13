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

    InsertElements(coll, 1, 9);

    // add 10 to each element
    std::for_each(coll.begin(), coll.end(),  // range
                  [] (int& elem) {           // operation
                      elem += 10;
                  });
    PrintElements(coll);

    // add value of first element to each element
    std::for_each(coll.begin(), coll.end(),
                  [=] (int& elem) {
                      elem += *coll.begin();
                  });
    PrintElements(coll);
}
