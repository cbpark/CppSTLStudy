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
#ifndef SRC_INCLUDE_SUM2A_H_
#define SRC_INCLUDE_SUM2A_H_

#include <istream>

namespace mylib {
    double ReadAndProcessSum(std::istream& strm) {
        double value, sum;

        // while stream is OK
        // - read value and add it to sum
        sum = 0;
        while (strm >> value) {
            sum += value;
        }

        if (!strm.eof()) {
            throw std::ios::failure("input error in ReadAndProcessSum()");
        }

        // return sum
        return sum;
    }
}

#endif  // SRC_INCLUDE_SUM2A_H_
