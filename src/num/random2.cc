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
#include <random>
#include <sstream>

void PrintNumbers(std::default_random_engine& dre) {
    for (int i = 0; i < 6; ++i) {
        std::cout << dre() << ' ';
    }
    std::cout << '\n';
}

int main() {
    // create engine and generate numbers
    std::default_random_engine dre;
    PrintNumbers(dre);

    // create equal engine and generate numbers
    std::default_random_engine dre2;  // same initial states as dre
    PrintNumbers(dre2);

    // create engine with initial state specified by a seed
    std::default_random_engine dre3(42);
    PrintNumbers(dre3);

    // save state of engine dre
    std::stringstream engine_state;
    engine_state << dre;

    // generate numbers according to current state of dre
    PrintNumbers(dre);

    // restore saved state of engine dre and create numbers again
    engine_state >> dre;
    PrintNumbers(dre);

    // restore saved state of engine dre,
    // skip 2 numbers and create numbers again
    engine_state.clear();   // clear EOF bit
    engine_state.seekg(0);  // and move read position to the beginning
    engine_state >> dre;
    dre.discard(2);
    PrintNumbers(dre);
}
