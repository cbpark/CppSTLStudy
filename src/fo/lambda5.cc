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
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string name_;
public:
    explicit Person(const std::string& n) : name_(n) { }
    void print() const {
        std::cout << name_ << '\n';
    }
    void print2(const std::string& prefix) const {
        std::cout << prefix << name_ << '\n';
    }
    // ...
};

int main() {
    std::vector<Person> coll =
        {Person("Tick"), Person("Trick"), Person("Track")};

    // call member function print() for each person
    std::for_each(coll.begin(), coll.end(),
                  [] (const Person& p) {
                      p.print();
                  });
    std::cout << '\n';

    // call member function print2() with additional argument for each person
    std::for_each(coll.begin(), coll.end(),
                  [] (const Person& p) {
                      p.print2("Person: ");
                  });
    std::cout << '\n';
}
