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
#include <cstdlib>   // for exit()
#include <fstream>   // for file I/O
#include <iomanip>   // for setw()
#include <iostream>  // for I/O
#include <string>    // for strings

// forward declarations
void WriteCharsetToFile(const std::string& filename);
void OutputFile(const std::string& filename);

int main() {
    WriteCharsetToFile("charset.out");
    OutputFile("charset.out");
}

void WriteCharsetToFile(const std::string& filename) {
    // open output file
    std::ofstream file(filename);

    // file opened?
    if (!file) {
        // NO, abort program
        std::cerr << "can't open output file \"" << filename << "\"\n";
        exit(EXIT_FAILURE);
    }

    // write character set
    for (int i = 32; i < 256; ++i) {
        file << "value: " << std::setw(3) << i << "  "
             << "char:  " << static_cast<char>(i) << '\n';
    }
}  // closes file automatically

void OutputFile(const std::string& filename) {
    // open input file
    std::ifstream file(filename);

    // file opened?
    if (!file) {
        // NO, abort program
        std::cerr << "can't open output file \"" << filename << "\"\n";
        exit(EXIT_FAILURE);
    }

    // copy file contents to cout
    char c;
    while (file.get(c)) {
        std::cout.put(c);
    }
}  // closes file automatically
