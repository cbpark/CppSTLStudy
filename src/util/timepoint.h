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
#ifndef SRC_UTIL_TIMEPOINT_H_
#define SRC_UTIL_TIMEPOINT_H_

#include <chrono>
#include <ctime>
#include <string>

// convert timepoint of system clock to calendar time string
inline std::string AsString(const std::chrono::system_clock::time_point& tp) {
    // convert to system time
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);  // convert to calendar time
    ts.resize(ts.size() - 1);    // skip trailing newline
    return ts;
}

// convert calendar time to timepoint of system clock
inline std::chrono::system_clock::time_point
MakeTimePoint(int year, int mon, int day, int hour, int min, int sec = 0) {
    struct std::tm t;
    // second of minute(0 .. 59 and 60 for leap seconds)
    t.tm_sec   = sec;
    // minute of hour (0 .. 59)
    t.tm_min   = min;
    // hour of day (0 .. 23)
    t.tm_hour  = hour;
    // day of month (0 .. 31)
    t.tm_mday  = day;
    // month of year (0 .. 11)
    t.tm_mon   = mon - 1;
    // year since 1900
    t.tm_year  = year - 1900;
    // determine whether daylight saving time
    t.tm_isdst = -1;

    std::time_t tt = std::mktime(&t);
    if (tt == -1) {
        throw "no valid system time";
    }

    return std::chrono::system_clock::from_time_t(tt);
}

#endif  // SRC_UTIL_TIMEPOINT_H_
