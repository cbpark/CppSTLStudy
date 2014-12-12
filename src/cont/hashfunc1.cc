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
    friend std::ostream& operator<<(std::ostream& strm, const Customer& c) {
        return strm << "[" << c.fname_ << "," << c.lname_ << ","
                    << c.no_ << "]\n";
    }
    friend struct CustomerHash;
    friend struct CustomerEqual;
};

struct CustomerHash {
    std::size_t operator()(const Customer& c) const {
        return hash_val(c.fname_, c.lname_, c.no_);
    }
};

struct CustomerEqual {
    bool operator()(const Customer& c1, Customer& c2) const {
        return c1.no_ == c2.no_;
    }
};

int main() {
    // unordered set with own hash function and equivalence criterion
    std::unordered_set<Customer, CustomerHash, CustomerEqual> cutset;

    cutset.insert(Customer("nico", "josuttis", 42));
    PrintElements(cutset);
}
