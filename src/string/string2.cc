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

int main() {
    const std::string delims(" \t,.;");
    std::string line;

    // for ever line read successfully
    while (std::getline(std::cin, line)) {
        std::string::size_type beg_idx, end_idx;

        // search beginning of the first word
        beg_idx = line.find_first_not_of(delims);

        // while beginning of a word found
        while (beg_idx != std::string::npos) {
            // search end of the actual word
            end_idx = line.find_first_of(delims, beg_idx);
            if (end_idx == std::string::npos) {
                // end of word is end of line
                end_idx = line.length();
            }

            // print characters in reverse order
            for (int i = end_idx - 1; i >= static_cast<int>(beg_idx); --i) {
                std::cout << line[i];
            }
            std::cout << ' ';

            // search beginning of the next word
            beg_idx = line.find_first_not_of(delims, end_idx);
        }
        std::cout << '\n';
    }
}
