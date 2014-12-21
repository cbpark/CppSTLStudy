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
#ifndef SRC_INCLUDE_IGNORE1_H_
#define SRC_INCLUDE_IGNORE1_H_

#include <istream>
#include <limits>

template<typename CharT, typename Traits>
inline
std::basic_istream<CharT, Traits>&
IgnoreLine(std::basic_istream<CharT, Traits>& strm) {
    // skip until end-olf-line
    strm.ignore(std::numeric_limits<std::streamsize>::max(),
                 strm.widen('\n'));

    // return stream for concatenation
    return strm;
}

#endif  // SRC_INCLUDE_IGNORE1_H_
