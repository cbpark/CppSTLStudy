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
#include <cstddef>
#include <cstdlib>
#include "algostuff.h"

struct MyRandom {
    std::ptrdiff_t operator()(std::ptrdiff_t max) {
        double tmp;
        tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        return static_cast<std::ptrdiff_t>(tmp * max);
    }
};

int main() {
    std::vector<int> coll;

    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:     ");

    // shuffle elements with self-written random-number generator
    MyRandom rd;
    std::random_shuffle(coll.begin(), coll.end(),  // range
                        rd);                       // random-number generator

    PrintElements(coll, "shuffled: ");
}
