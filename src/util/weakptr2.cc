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
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Person {
    std::string name;
    std::shared_ptr<Person> mother;
    std::shared_ptr<Person> father;
    std::vector<std::weak_ptr<Person>> kids;  // weak pointer!!!

    Person(const std::string& n,
           std::shared_ptr<Person> m = nullptr,
           std::shared_ptr<Person> f = nullptr)
        : name(n), mother(m), father(f) {
    }

    ~Person() {
        std::cout <<"delete " << name << '\n';
    }
};

std::shared_ptr<Person> InitFamily(const std::string& name) {
    std::shared_ptr<Person> mom(new Person(name + "'s mom"));
    std::shared_ptr<Person> dad(new Person(name + "'s dad"));
    std::shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

int main() {
    std::shared_ptr<Person> p = InitFamily("nico");

    std::cout << "nico's family exists\n";
    std::cout << "- nico is shared " << p.use_count() << " times\n";
    std::cout << "- name of 1st kid of nico's mom: "
              << p->mother->kids[0].lock()->name << '\n';

    p = InitFamily("jim");
    std::cout << "jim's family exists\n";
}
