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

bool LessLength(const std::string& s1, const std::string& s2) {
    return s1.length() < s2.length();
}

int main() {
    // fill two collections with the same elements
    std::vector<std::string> coll1 = {"1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
                                      "7xx", "8xxx", "9xx", "10xxx", "11", "12",
                                      "13", "14xx", "15", "16", "17"};
    std::vector<std::string> coll2(coll1);

    PrintElements(coll1, "on entry:\n");

    // sort (according to the length of the strings)
    std::sort(coll1.begin(), coll1.end(),  // range
              LessLength);                 // criterion
    std::stable_sort(coll2.begin(), coll2.end(),  // range
                     LessLength);                 // criterion

    PrintElements(coll1, "\nwith sort():\n");
    PrintElements(coll2, "\nwith stable_sort():\n");
}
