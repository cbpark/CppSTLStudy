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
#include <string>

int main() {
    // create multimap as string/string dictionary
    std::multimap<std::string, std::string> dict;

    // insert some elements in random order
    dict.insert({
            {"day",     "Tag"},
            {"strange", "fremd"},
            {"car",     "Auto"},
            {"smart",   "elegant"},
            {"trait",   "Merkmal"},
            {"strange", "seltsam"},
            {"smart",   "raffiniert"},
            {"smart",   "klug"},
            {"clever",  "raffiniert"}
        });

    // print all elements
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout << ' ' << std::setw(10) << "english "
              << "german\n";
    std::cout << std::setfill('-') << std::setw(20) << ""
              << std::setfill(' ') << '\n';
    for (const auto& elem : dict) {
        std::cout << ' ' << std::setw(10) << elem.first
                  << elem.second << '\n';
    }
    std::cout << '\n';

    // print all values for key "smart"
    std::string word("smart");
    std::cout << word << ": \n";
    for (auto pos = dict.lower_bound(word);
         pos != dict.upper_bound(word);
         ++pos) {
        std::cout << "    " << pos->second << '\n';
    }

    // print all keys for value "raffiniert"
    word = ("raffiniert");
    std::cout << word << ": \n";
    for (const auto& elem : dict) {
        if (elem.second == word) {
            std::cout << "    " << elem.first << '\n';
        }
    }
}
