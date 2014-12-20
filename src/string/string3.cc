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
#include <iterator>
#include <locale>
#include <string>

int main() {
    std::string input;

    // don't skip leading whitespaces
    std::cin.unsetf(std::ios::skipws);

    // read all characters while compressing whitespace
    const std::locale& loc(std::cin.getloc());  // locale
    std::unique_copy(std::istream_iterator<char>(std::cin),  // beginning of source
                     std::istream_iterator<char>(),          // end of source
                     std::back_inserter(input),              // destination
                     [=] (char c1, char c2) {                // criterion for adj. duplicates
                         return std::isspace(c1, loc) && std::isspace(c2, loc);
                     });

    // process input
    // - here: write it to the standard output
    std::cout << input;
}
