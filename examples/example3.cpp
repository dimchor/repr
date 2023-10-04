#include "../include/repr.h"

#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>

int main()
{
    /*
    static_assert(dl::IsIterator<int>);
    static_assert(dl::IsIterator<float>);

    // it's not really an iterator, but it certainly acts like one so it's
    // not that big of deal
    static_assert(dl::IsIterator<int*>);

    // yay, it works
    static_assert(dl::IsIterator<std::vector<int>::iterator>);

    // these work, too
    static_assert(dl::IsIteratable<std::vector<int>>);
    static_assert(dl::IsIteratable<std::list<int>>);
    static_assert(dl::IsIteratable<std::map<int, int>>);

    static_assert(dl::IsIteratable<std::stack<int>>);
    */

    std::vector<int> v{1, 2, 3, 4};
    std::cout << dl::repr(v) << '\n';

    std::set<int> container{};
    //container.resize(10000);

    container.insert(9);

    std::cout << dl::repr(container) << '\n';

    return 0;
}
