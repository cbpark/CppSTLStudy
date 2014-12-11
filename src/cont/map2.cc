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
    // create map / associative array
    // - keys are strings
    // - values are doubles
    using StringDoubleMap = std::map<std::string, double>;

    StringDoubleMap stocks;  // create empty container

    // insert some elements
    stocks["BASF"]    = 369.50;
    stocks["VW"]      = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"]     = 834.00;
    stocks["Siemens"] = 842.20;

    // print all elements
    StringDoubleMap::iterator pos;
    std::cout << std::left;  // left-adjusted values
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        std::cout << "stock: " << std::setw(12) << pos->first
                  << "price: " << pos->second << '\n';
    }
    std::cout << '\n';

    // boom (all prices doubled)
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        pos->second *= 2;
    }

    // print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        std::cout << "stock: " << std::setw(12) << pos->first
                  << "price: " << pos->second << '\n';
    }
    std::cout << '\n';

    // rename key from "VW" to "Volkswagen"
    // - provided only by exchanging element
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    // print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        std::cout << "stock: " << std::setw(12) << pos->first
                  << "price: " << pos->second << '\n';
    }
}
