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
#include <exception>
#include <iostream>
#include <limits>
#include <string>

int main() {
    try {
        // convert to numeric type
        std::cout << std::stoi("  77") << '\n';
        std::cout << std::stod("  77.7") << '\n';
        std::cout << std::stoi("-0x77") << '\n';

        // use index of characters not processed
        std::size_t idx;

        std::cout << std::stoi("  42 is the truth", &idx) << '\n';
        std::cout << "  idx of first unprocessed char: " << idx << '\n';

        // use base 16 and 18
        std::cout << std::stoi("  42", nullptr, 16) << '\n';
        std::cout << std::stoi("789", &idx, 8) << '\n';
        std::cout << "  idx of first unprocessed char: " << idx << '\n';

        // convert numeric value to string
        long long ll = std::numeric_limits<long long>::max();
        std::string s = std::to_string(ll);  // converts maximum long long to string
        std::cout << s << '\n';

        // try to convert back
        std::cout << std::stoi(s) << '\n';  // throws out_of_range
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
