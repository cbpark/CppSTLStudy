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
#ifndef SRC_STL_PRINT_H_
#define SRC_STL_PRINT_H_

#include <iostream>
#include <string>

// PrintElements()
// - prints optional string optstr followed by
// - all elements of the collection col
// - in one line, separated by spaces
template <typename T>
inline void PrintElement(const T& coll, const std::string& optstr="") {
    std::cout << optstr;
    for (const auto& elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

#endif  // SRC_STL_PRINT_H_
