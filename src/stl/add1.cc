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

// function object that adds the value with which it is initialized
class AddValue {
private:
    int the_value;  // the value to add
public:
    // constructor initialize the values to add
    AddValue(int v) : the_value(v) { }

    // the ``function call'' for the element adds the value
    void operator()(int& elem) const {
        elem += the_value;
    }
};

int main() {
    std::list<int> coll;

    // insert elements from 1 to 9
    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }

    PrintElements(coll, "initialized:                ");

    // add value 10 to each element
    std::for_each(coll.begin(), coll.end(),  // range
                  AddValue(10));             // operation

    PrintElements(coll, "after adding 10:            ");

    // add value of first element to each element
    std::for_each(coll.begin(), coll.end(),  // range
                  AddValue(*coll.begin()));  // operation

    PrintElements(coll, "after adding first element: ");
}
