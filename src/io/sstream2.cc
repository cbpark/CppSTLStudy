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
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

std::tuple<std::string, std::string, std::string> ParseName(std::string name) {
    std::string s1, s2, s3;
    std::istringstream(name) >> s1 >> s2 >> s3;
    if (s3.empty()) {
        return std::tuple<std::string, std::string, std::string>(std::move(s1),
                                                                 "",
                                                                 std::move(s2));
    } else {
        return std::tuple<std::string, std::string, std::string>(std::move(s1),
                                                                 std::move(s2),
                                                                 std::move(s3));
    }
}

int main() {
    auto t1 = ParseName("Nicolai M. Josuttis");
    std::cout << "firstname: " << std::get<0>(t1) << '\n';
    std::cout << "middle:    " << std::get<1>(t1) << '\n';
    std::cout << "lastname:  " << std::get<2>(t1) << '\n';
    auto t2 = ParseName("Nico Josuttis");
    std::cout << "firstname: " << std::get<0>(t2) << '\n';
    std::cout << "middle:    " << std::get<1>(t2) << '\n';
    std::cout << "lastname:  " << std::get<2>(t2) << '\n';
}
