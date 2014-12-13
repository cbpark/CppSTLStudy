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
#include <cstdlib>

int main() {
    std::list<int> coll;

    // insert five random numbers
    std::generate_n(std::back_inserter(coll), 5, rand);
    PrintElements(coll);

    // overwrite with five new random numbers
    std::generate(coll.begin(), coll.end(), rand);
    PrintElements(coll);
}
