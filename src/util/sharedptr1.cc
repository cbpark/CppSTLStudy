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

int main() {
    // two shared pointers representing two persons by their name
    // std::shared_ptr<std::string> p_nico(new std::string("nico"));
    // std::shared_ptr<std::string> p_jutta(new std::string("jutta"));
    std::shared_ptr<std::string> p_nico =
        std::make_shared<std::string>("nico");
    std::shared_ptr<std::string> p_jutta =
        std::make_shared<std::string>("jutta");

    std::shared_ptr<std::string> p_nico4;
    p_nico4.reset(new std::string("nico"));

    // capitalize person names
    (*p_nico)[0] = 'N';
    p_jutta->replace(0, 1, "J");

    // put them multiple times in a container
    std::vector<std::shared_ptr<std::string>> who_made_coffee;
    who_made_coffee.push_back(p_jutta);
    who_made_coffee.push_back(p_jutta);
    who_made_coffee.push_back(p_nico);
    who_made_coffee.push_back(p_jutta);
    who_made_coffee.push_back(p_nico);

    // print all elements
    for (auto ptr : who_made_coffee) {
        std::cout << *ptr << "  ";
    }
    std::cout << '\n';

    // overwrite a name again
    *p_nico = "Nicolai";

    // print all elements again
    for (auto ptr : who_made_coffee) {
        std::cout << *ptr << "  ";
    }
    std::cout << '\n';

    // print some internal data
    std::cout << "use_count: " << who_made_coffee[0].use_count() << '\n';
}
