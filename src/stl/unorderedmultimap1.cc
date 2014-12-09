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
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

int main() {
    // container for int/string values
    std::unordered_multimap<std::string, double> coll {{"tim",     9.9  },
                                                       {"struppi", 11.77}};

    // square the value of each element
    for (std::pair<const std::string, double>& elem : coll) {
        elem.second *= elem.second;
    }

    // print all element (key and value)
    for (const auto& elem : coll) {
        std::cout << elem.first << ": " << elem.second << '\n';
    }
}
