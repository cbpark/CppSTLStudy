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
#include <tuple>
#include <utility>

struct Foo {
    explicit Foo(std::tuple<int, double>) {
        std::cout << "Foo::Foo(tuple)\n";
    }
    template <typename... Args>
    Foo(Args... args) {
        std::cout << "Foo::Foo(args...)\n";
    }
};

int main() {
    // create tuple t.
    std::tuple<int, double> t(1, 2.22);

    // pass the tuple as a whole to the constructor of Foo.
    std::pair<int, Foo> p1(42, t);

    // pass the elements of the tuple to the constructor of Foo.
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
}
