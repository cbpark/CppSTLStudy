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
#include "hashval.h"
#include "print.h"
#include <iostream>
#include <string>
#include <unordered_set>

class Customer {
private:
    std::string fname_;
    std::string lname_;
    long        no_;
public:
    Customer(const std::string& fn, const std::string& ln, long n)
        : fname_(fn), lname_(ln), no_(n) { }
    std::string firstname() const {
        return fname_;
    }
    std::string lastname() const {
        return lname_;
    }
    long number() const {
        return no_;
    }
    friend std::ostream& operator<<(std::ostream& strm, const Customer& c) {
        return strm << "[" << c.fname_ << "," << c.lname_ << ","
                    << c.no_ << "]\n";
    }
};

int main() {
    // lambda for user-defined hash function
    auto hash = [] (const Customer& c) {
        return hash_val(c.firstname(), c.lastname(), c.number());
    };

    // lambda for user-defined equality criterion
    auto eq = [] (const Customer& c1, Customer& c2) {
        return c1.number() == c2.number();
    };

    // create unordered set with user-defined behavior
    std::unordered_set<Customer, decltype(hash), decltype(eq)> cutset(10,
                                                                      hash, eq);
    cutset.insert(Customer("nico", "josuttis", 42));
    PrintElements(cutset);
}
