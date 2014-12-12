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
#ifndef SRC_INCLUDE_ASSOITER_H_
#define SRC_INCLUDE_ASSOITER_H_

#include <iterator>

// class template for insert iterator for associative and unordered containers
template<typename Container>
class AssoInsertIterator : public std::iterator<std::output_iterator_tag,
                                               typename Container::value_type> {
protected:
    Container& container;  // container in which elements are inserted

public:
    // constructor
    explicit AssoInsertIterator(Container& c) : container(c) { }

    // assignment operator
    // - inserts a value into the container
    AssoInsertIterator<Container>&
    operator=(const typename Container::value_type& value) {
        container.insert(value);
        return *this;
    }

    // deferencing is a no-op that returns the iterator itself
    AssoInsertIterator<Container>& operator*() {
        return *this;
    }

    // increment operation is a no-op that returns the iterator itself
    AssoInsertIterator<Container>& operator++() {
        return *this;
    }
    AssoInsertIterator<Container>& operator++(int) {
        return *this;
    }
};

// convenience function to create the inserter
template<typename Container>
inline AssoInsertIterator<Container> asso_inserter(Container& c) {
    return AssoInsertIterator<Container>(c);
}

#endif  // SRC_INCLUDE_ASSOITER_H_
