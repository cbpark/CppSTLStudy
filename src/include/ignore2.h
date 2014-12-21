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
#ifndef SRC_INCLUDE_IGNORE2_H_
#define SRC_INCLUDE_IGNORE2_H_

#include <istream>
#include <limits>

class IgnoreLine {
private:
    int num_;
public:
    explicit IgnoreLine(int n = 1) : num_(n) { }

    template <typename CharT, typename Traits>
    friend std::basic_istream<CharT, Traits>&
    operator>>(std::basic_istream<CharT, Traits>& strm,
               const IgnoreLine& ign) {
        // skip until end-olf-line num times
        for (int i = 0; i < ign.num_; ++i) {
            strm.ignore(std::numeric_limits<std::streamsize>::max(),
                        strm.widen('\n'));
        }

        // return stream for concatenation
        return strm;
    }
};

#endif  // SRC_INCLUDE_IGNORE2_H_
