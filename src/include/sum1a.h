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
#ifndef SRC_INCLUDE_SUM1A_H_
#define SRC_INCLUDE_SUM1A_H_

#include <istream>

namespace mylib {
    double ReadAndProcessSum(std::istream& strm) {
        double value, sum;

        // save current state of exception flags
        std::ios::iostate old_exceptions = strm.exceptions();

        // let failbit and badbit throw exceptions
        // - NOTE: failbit is also set at end-of-file
        strm.exceptions(std::ios::failbit | std::ios::badbit);

        try {
            // while stream is OK
            // - read value and add it to sum
            sum = 0;
            while (strm >> value) {
                sum += value;
            }
        } catch (...) {
            // if exception not caused by end-of-file
            // - restore old state of exception flags
            // - rethrow exception
            if (!strm.eof()) {
                strm.exceptions(old_exceptions);  // restore exception flags
                throw;                            // rethrow
            }
        }

        // restore old state of exception flags
        strm.exceptions(old_exceptions);

        // return sum
        return sum;
    }
}

#endif  // SRC_INCLUDE_SUM1A_H_
