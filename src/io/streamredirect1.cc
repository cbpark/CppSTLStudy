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
#include <fstream>
#include <iostream>
#include <memory>

void Redirect(std::ostream&);

int main() {
    std::cout << "the first row\n";

    Redirect(std::cout);

    std::cout << "the last row\n";
}

void Redirect (std::ostream& strm) {
    // save output buffer of the stream
    // - use unique pointer with deleter that ensures to restore
    //   the original output buffer at the end of the function
    auto del = [&] (std::streambuf *p) {
                   strm.rdbuf(p);
               };
    std::unique_ptr<std::streambuf, decltype(del)> origBuffer(strm.rdbuf(),
                                                              del);

    // redirect ouput into the file redirect.txt
    std::ofstream file("redirect.txt");
    strm.rdbuf(file.rdbuf());

    file << "one row for the file\n";
    strm << "one row for the stream\n";
}  // closes file AND its buffer automatically
