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
#include <string>

int main() {
    // create consant string
    const std::string hello("Hello, how are you?");

    // initialize string s with all characters of string hello
    std::string s(hello.cbegin(), hello.cend());

    // ranged-based for loop that iterates through all the characters
    for (char c : s) {
        std::cout << c;
    }
    std::cout << '\n';

    // reverse the order of all characters inside the string
    std::reverse(s.begin(), s.end());
    std::cout << "reverse:       " << s << '\n';

    // sort all characters inside the string
    std::sort(s.begin(), s.end());
    std::cout << "ordered:       " << s << '\n';

    // remove adjacent duplicates
    // - unique() reorders and returns new end
    // - erase() shrinks accordingly
    s.erase(std::unique(s.begin(), s.end()), s.end());
    std::cout << "no duplicates: " << s << '\n';
}
