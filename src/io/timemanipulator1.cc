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
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {
    // process and print current date and time
    auto now = std::chrono::system_clock::now();
    time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&t);
    std::cout << std::put_time(now_tm, "date: %x\ntime: %X\n") << '\n';

    // read date
    std::tm* date = nullptr;
    std::cout << "new date: ";
    std::cin >> std::get_time(date, "%x");  // read date
    if (!std::cin) {
        std::cerr << "invalid format read\n";
    }
}
