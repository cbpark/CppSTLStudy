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
#include <iterator>
#include <list>

class IntSequence {
private:
    int value_;
public:
    IntSequence(int initial_value)  // constructor
        : value_(initial_value) { }

    int operator()() {              // ``function call''
        return ++value_;
    }
};

int main() {
    std::list<int> coll;

    // insert values from 1 to 9
    std::generate_n(std::back_inserter(coll),  // start
                    9,                         // number of elements
                    IntSequence(1));           // generate values, starting with 1

    PrintElements(coll);

    // replace second to last element but one with value starting at 42
    std::generate(std::next(coll.begin()),  // start
                  std::prev(coll.end()),    // end
                  IntSequence(42));         // generate values, starting with 42

    PrintElements(coll);
}
