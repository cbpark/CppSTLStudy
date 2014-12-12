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
#include <cstdio>  // for remove()
#include <fstream>
#include <memory>
#include <string>

class FileDeleter {
private:
    std::string filename_;
public:
    explicit FileDeleter(const std::string& fn) : filename_(fn) { }

    void operator()(std::ofstream* fp) {
        fp->close();                    // close file
        std::remove(filename_.c_str());  // delete file
    }
};

int main() {
    // create an open temporary file
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
                                      FileDeleter("tmpfile.txt"));
}
