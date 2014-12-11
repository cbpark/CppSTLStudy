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
#include <iterator>
#include <set>
#include <string>

class Item {
private:
    std::string name;
    double price;

public:
    explicit Item(const std::string& n, double p = 0)
        : name(n), price(p) { }
    std::string get_name() const {
        return name;
    }
    void set_name(const std::string& n) {
        name = n;
    }
    double get_price() const {
        return price;
    }
    void set_price(double p) {
        price = p;
    }
};

template <typename Coll>
void PrintItems(const std::string& msg, const Coll& coll) {
    std::cout << msg << '\n';
    for (const auto& elem : coll) {
        std::cout << ' ' << elem->get_name() << ": "
                         << elem->get_price() << '\n';
    }
}

int main() {
    // two different collections sharing Items
    using ItemPtr = std::shared_ptr<Item>;
    std::set<ItemPtr> all_items;
    std::deque<ItemPtr> bestsellers;

    // insert objects into the collections
    // - besesellers are in both collections
    bestsellers = {ItemPtr(new Item("Kong Yize", 20.10)),
                   ItemPtr(new Item("A Midsummer Night's Dream", 14.99)),
                   ItemPtr(new Item("The Maltese Falcon", 9.88))};
    all_items = {ItemPtr(new Item("Walter", 0.44)),
                 ItemPtr(new Item("Pizza", 2.22))};
    all_items.insert(bestsellers.begin(), bestsellers.end());

    // print contents of both collections
    PrintItems("bestsellers:", bestsellers);
    PrintItems("all:", all_items);
    std::cout << '\n';

    // double price of bestsellers
    std::for_each(bestsellers.begin(), bestsellers.end(),
                  [] (std::shared_ptr<Item>& elem) {
                      elem->set_price(elem->get_price() * 2);
                  });

    // replace second bestsellers by first item with name "Pizza"
    bestsellers[1] = *(std::find_if(all_items.begin(), all_items.end(),
                                    [] (std::shared_ptr<Item> elem) {
                                        return elem->get_name() == "Pizza";
                                    }));

    // set price of first bestseller
    bestsellers[0]->set_price(44.77);

    // print contents of both collections
    PrintItems("bestsellers:", bestsellers);
    PrintItems("all:", all_items);
}
