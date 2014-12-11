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
#include <iomanip>
#include <iostream>
#include <map>
#include <utility>

int main() {
    // map with doubles as key and value
    // - initializing keys and values are automatically converted to double
    std::map<double, double> coll = {{1, 7}, {2, 4}, {3, 2}, {4, 3},
                                     {5, 6}, {6, 1}, {7, 3}};

    // search an element with key 3.0 (logarithmic complexity)
    auto pos_key = coll.find(3.0);
    if (pos_key != coll.end()) {
        std::cout << "key 3.0 found ("
                  << pos_key->first << ":"
                  << pos_key->second << ")\n";
    }

    // search an element with value 3.0 (linear complexity)
    auto pos_val = std::find_if(coll.begin(), coll.end(),
                                [] (const std::pair<double, double>& elem) {
                                    return elem.second == 3.0;
                                });
    if (pos_val != coll.end()) {
        std::cout << "value 3.0 found ("
                  << pos_val->first << ":"
                  << pos_val->second << ")\n";
    }
}
