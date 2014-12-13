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
#include "print.h"
#include <algorithm>
#include <iostream>
#include <list>

class Nth {  // function object that returns true for the nth call
private:
    int nth_;    // call for which to return true
    int count_;  // call counter;
public:
    Nth(int n) : nth_(n), count_(0) { }
    bool operator()(int) {
        return ++count_ == nth_;
    }
};

int main() {
    std::list<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintElements(coll, "coll:        ");

    // remove third element
    std::list<int>::iterator pos;
    pos = std::remove_if(coll.begin(), coll.end(),  // range
                         Nth(3));                   // remove criterion
    coll.erase(pos, coll.end());

    PrintElements(coll, "3rd removed: ");
}
