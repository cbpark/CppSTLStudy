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
    std::vector<int> coll1 = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    PrintElements(coll1, "coll1: ");

    // check whether coll1 is sorted
    if (std::is_sorted(coll1.begin(), coll1.end())) {
        std::cout << "coll1 is sorted\n";
    } else {
        std::cout << "coll1 is not sorted\n";
    }

    std::map<int, std::string> coll2;
    coll2 = {{1, "Bill"}, {2, "Jim"}, {3, "Nico"}, {4, "Liu"}, {5, "Ai"}};
    PrintMappedElements(coll2, "coll2: ");

    // define predicate to compare names
    auto compare_name = [] (const std::pair<int, std::string>& e1,
                            const std::pair<int, std::string>& e2) {
        return e1.second < e2.second;
    };

    // check whether the names in coll2 are sorted
    if (std::is_sorted(coll2.cbegin(), coll2.cend(), compare_name)) {
        std::cout << "names in coll2 are sorted\n";
    } else {
        std::cout << "names in coll2 are not sorted.\n";
    }

    // print first unsorted name
    auto pos = std::is_sorted_until(coll2.cbegin(), coll2.cend(), compare_name);
    if (pos != coll2.end()) {
        std::cout << "first unsorted name: " << pos->second << '\n';
    }
}
