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
    InsertElements(coll, 1, 3);
    PrintElements(coll, "on entry:  ");

    // permute element until they are sorted
    // - runs through all permutations because the elements are sorted now
    while (std::next_permutation(coll.begin(), coll.end())) {
        PrintElements(coll, " ");
    }
    PrintElements(coll, "afterward: ");

    // permute until descending sorted
    // - this is the next permuatation after ascending sorting
    // - so the loop ends immediately
    while (std::prev_permutation(coll.begin(), coll.end())) {
        PrintElements(coll, " ");
    }
    PrintElements(coll, "now:       ");

    // permute elements until they are sorted in descending order
    // - runs through all permutations because the elements are sorted in
    // descending order now
    while (std::prev_permutation(coll.begin(), coll.end())) {
        PrintElements(coll, " ");
    }
    PrintElements(coll, "afterward: ");
}
