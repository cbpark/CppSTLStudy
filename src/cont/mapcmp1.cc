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
#include <cctype>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

// function object to compare strings
// - allows you to set the comparison criterion at runtime
// - allows you to compare case insensitive
class RuntimeStringCmp {
public:
    // constants for the comparsion criterion
    enum CmpMode {kNormal, kNoCase};

private:
    // actual comparison mode
    const CmpMode mode;

    // auxiliary function to compare case insensitive
    static bool nocase_compare(char c1, char c2) {
        return std::toupper(c1) < std::toupper(c2);
    }

public:
    // constructor: initialize the comparison criterion
    explicit RuntimeStringCmp(CmpMode m = kNormal) : mode(m) { }

    // the comparison
    bool operator()(const std::string& s1, const std::string& s2) const {
        if (mode == kNormal) {
            return s1 < s2;
        } else {
            return std::lexicographical_compare(s1.begin(), s1.end(),
                                                s2.begin(), s2.end(),
                                                nocase_compare);
        }
    }
};

// container type
// - map with
//    - string keys
//    - string values
//    - the special comparison object type
using StringStringMap = std::map<std::string, std::string, RuntimeStringCmp>;

// function that fills and prints such containers
void FillAndPrint(StringStringMap& coll);

int main() {
    // create a container with the default comparison criterion
    StringStringMap coll1;
    FillAndPrint(coll1);

    // create an object for case-insensitive comparsions
    RuntimeStringCmp ignorecase(RuntimeStringCmp::kNoCase);

    // create a container with the case-insensitive comparisons criterion
    StringStringMap coll2(ignorecase);
    FillAndPrint(coll2);
}

void FillAndPrint(StringStringMap& coll) {
    // insert elements in random order
    coll["Deutschland"] = "Germany";
    coll["deutsch"] = "German";
    coll["Haken"] = "snag";
    coll["arbeiten"] = "work";
    coll["Hund"] = "dog";
    coll["gehen"] = "go";
    coll["Unternehmen"] = "enterprise";
    coll["unternehmen"] = "undertake";
    coll["gehen"] = "walk";
    coll["Bestatter"] = "undertaker";

    // print elements
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    for (const auto& elem : coll) {
        std::cout << std::setw(15) << elem.first << ' '
                  << elem.second << '\n';
    }
    std::cout << '\n';
}
