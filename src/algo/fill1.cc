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
    // print then times 7.7
    std::fill_n(std::ostream_iterator<double>(std::cout, " "), 10, 7.7);
    std::cout << '\n';

    std::list<std::string> coll;

    // insert "hello" nine times
    std::fill_n(std::back_inserter(coll), 9, "hello");
    PrintElements(coll, "coll: ");

    // overwrite all elements with "again"
    std::fill(coll.begin(), coll.end(), "again");
    PrintElements(coll, "coll: ");

    // replace all but two elements with "hi"
    std::fill_n(coll.begin(), coll.size() - 2, "hi");
    PrintElements(coll, "coll: ");

    // replace the second and up to the last element but one with "hmmm"
    std::list<std::string>::iterator pos1, pos2;
    pos1 = coll.begin();
    pos2 = coll.end();
    std::fill(++pos1, --pos2, "hmmm");
    PrintElements(coll, "coll: ");
}
