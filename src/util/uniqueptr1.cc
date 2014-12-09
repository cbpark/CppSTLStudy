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
#include <dirent.h>  // for opendir()

#include <iostream>
#include <cerrno>    // for errno
#include <cstring>   // for strerror()
#include <memory>
#include <string>

struct DirCloser {
    void operator()(DIR* dp) {
        if (closedir(dp) != 0) {
            std::cerr << "OOPS: closedir() failed\n";
        }
    }
};

int main() {
    // open current directory
    std::unique_ptr<DIR, DirCloser> p_dir(opendir("."));

    // processes each directory entry
    struct dirent *dp;
    while ((dp = readdir(p_dir.get())) != nullptr) {
        std::string filename(dp->d_name);
        std::cout << "process " << filename << '\n';
        // ...
    }
}
