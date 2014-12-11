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
#include <ctime>
#include <string>
#include <iostream>
#include <ratio>

std::string AsString(const std::chrono::system_clock::time_point& tp) {
    // convert to system time
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);  // convert to calendar time
    ts.resize(ts.size() - 1);         // skip trailing newline
    return ts;
}

int main() {
    // define type for durations that represent day(s)
    using Days = std::chrono::duration<int, std::ratio<3600*24>>;

    // process the epoch of this system clock
    std::chrono::time_point<std::chrono::system_clock> tp;
    std::cout << "epoch: " << AsString(tp) << '\n';

    // add one day, 23 hours, and 55 minutes
    tp += Days(1) + std::chrono::hours(23) + std::chrono::minutes(55);
    std::cout << "later: " << AsString(tp) << '\n';

    // process difference from epoch in minutes and days
    auto diff = tp - std::chrono::system_clock::time_point();
    std::cout << "diff: "
              << std::chrono::duration_cast<std::chrono::minutes>(diff).count()
              << " minute(s)\n";
    Days days = std::chrono::duration_cast<Days>(diff);
    std::cout << "diff: " << days.count() << " day(s)\n";

    // subtract one year (hoping it is valid and not a leap year)
    tp -= std::chrono::hours(24*365);
    std::cout << "-1 year: " << AsString(tp) << '\n';

    // subtract 50 years (hoping it is valid and ignoring leap years)
    tp -= std::chrono::duration<int, std::ratio<3600*24*365>>(50);
    std::cout << "-50 years: " << AsString(tp) << '\n';

    // sutract 50 years (hoping it is valid and ignoring leap years)
    tp -= std::chrono::duration<int, std::ratio<3600*24*365>>(50);
    std::cout << "-50 years: " << AsString(tp) << '\n';
}
