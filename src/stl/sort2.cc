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
#include <deque>
#include <iostream>
#include <string>

class Person {
private:
    std::string fn_;
    std::string ln_;
public:
    Person() { }
    Person(const std::string& f, const std::string& n)
        : fn_(f), ln_(n) {
    }
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

int main() {
    std::deque<Person> coll;
    // ...

    // sort Persons according to lastname (and firstname)
    std::sort(coll.begin(), coll.end(),                  // range
              [] (const Person& p1, const Person& p2) {  // sort criterion
                  return p1.lastname() < p2.lastname() ||
                                         (p1.lastname() == p2.lastname() &&
                                          p1.firstname() < p2.firstname());

              });

    // ...
}
