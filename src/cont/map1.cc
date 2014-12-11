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
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, double> coll {{"tim",     9.9},
                                        {"struppi", 11.77}};

    // square the value of each element
    std::for_each(coll.begin(), coll.end(),
                  [] (std::pair<const std::string, double>& elem) {
                      elem.second *= elem.second;
                  });

    // print each element
    std::for_each(coll.begin(), coll.end(),
                  [] (const decltype(coll)::value_type& elem) {
                      std::cout << elem.first << ": " << elem.second << '\n';
                  });
}
