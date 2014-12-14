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
#include <random>
#include "algostuff.h"

int main() {
    std::vector<int> coll;

    InsertElements(coll, 1, 9);
    PrintElements(coll, "coll:     ");

    // shuffle all elements randomly
    std::random_shuffle(coll.begin(), coll.end());

    PrintElements(coll, "shuffled: ");

    // sort them again
    std::sort(coll.begin(), coll.end());
    PrintElements(coll, "sorted:   ");

    // shuffle elements with default engine
    std::default_random_engine dre;
    std::shuffle(coll.begin(), coll.end(),  // range
                 dre);                      // random-number generator

    PrintElements(coll, "shuffled: ");
}
