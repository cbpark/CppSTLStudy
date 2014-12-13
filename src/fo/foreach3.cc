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
#include <algorithm>
#include <iostream>
#include <vector>

// function object to process the mean value
class MeanValue {
private:
    long num_;  // number of elements
    long sum_;  // sum of all element values
public:
    // constructor
    MeanValue() : num_(0), sum_(0) { }

    // ``function call''
    // - process one more element of the sequence
    void operator()(int elem) {
        ++num_;        // increment count
        sum_ += elem;  // add value
    }

    // return mean value
    double value() {
        return static_cast<double>(sum_) / static_cast<double>(num_);
    }
};

int main() {
    std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8};

    // process and print mean value
    MeanValue mv = std::for_each(coll.begin(), coll.end(),  // range
                                 MeanValue());              // operation
    std::cout << "mean value: " << mv.value() << '\n';
}
