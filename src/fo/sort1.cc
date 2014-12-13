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
#include <algorithm>
#include <iostream>
#include <set>
#include <string>

class Person {
private:
    std::string fn_;
    std::string ln_;
public:
    Person() { }
    Person(const std::string& f, const std::string& n) : fn_(f), ln_(n) { }
    std::string firstname() const;
    std::string lastname() const;
    // ...
};

inline std::string Person::firstname() const {
    return fn_;
}

inline std::string Person::lastname() const {
    return ln_;
}

// class for function predicate
// - operator() returns whether a person is less than another person
class PersonSortCriterion {
public:
    bool operator()(const Person& p1, const Person& p2) const {
        // a person is less than another person
        // - if the last name is less
        // - if the last name is equal and the first name is less
        return p1.lastname() < p2.lastname() ||
                               (p1.lastname() == p2.lastname() &&
                                p1.firstname() < p2.firstname());
    }
};

int main() {
    // create a set with special sorting criterion
    std::set<Person, PersonSortCriterion> coll;
    // ...

    // do something with the elements
    for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
        // ...
    }
    // ...
}
