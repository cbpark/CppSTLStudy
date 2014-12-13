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
    IntSequence seq(1);  // integarl sequence starting with 1

    // insert values from 1 to 4
    // - pass function object by reference
    //   so that it will continue with 5
    std::generate_n<std::back_insert_iterator<std::list<int>>,
                    int, IntSequence&>(std::back_inserter(coll),  // start
                                       4,  // number of elements
                                       seq);  // generate values
    PrintElements(coll);

    // insert values from 42 to 45
    std::generate_n(std::back_inserter(coll),  // start
                    4,                         // number of elements
                    IntSequence(42));          // generates values
    PrintElements(coll);


    // continue with first sequence
    // - pass function object by value
    //   so that it will continue with 5 again
    std::generate_n(std::back_inserter(coll),  // start
                    4,                         // number of elements
                    seq);                      // generate values
    PrintElements(coll);

    // continue with first sequence again
    std::generate_n(std::back_inserter(coll),  // start
                    4,                         // number of elements
                    seq);                      // generate values
    PrintElements(coll);
}
