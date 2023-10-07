#include "../include/repr.h"

#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <deque>
#include <forward_list>
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

    std::map<int, int> m{};
    m[1] = 2;
    m[3] = 8;

    std::cout << dl::quoted(dl::repr(dl::quoted(m))) << '\n';

    std::cout << dl::repr(dl::quoted(std::make_pair(7, 8))) << '\n';

    std::cout << dl::repr(dl::quoted(std::make_tuple("float", 3.14, -8), '%')) 
        << '\n';

    std::deque<int> d{1, 2, 3, 4};
    std::cout << dl::repr(d) << '\n';

    std::forward_list<float> fl{1.1f, 2.2f, 3.3f, 4.4f};
    std::cout << dl::repr(fl) << '\n';

    std::list<bool> l{true, false, true, false};
    std::cout << dl::repr(l) << '\n';

    std::multiset<double> ms{1.2, 2.3, 3.4, 3.4};
    std::cout << dl::repr(ms) << '\n';

    std::multimap<int, int> mm{};
    mm.insert(std::make_pair(1, 2));
    mm.insert(std::make_pair(3, 8));
    mm.insert(std::make_pair(3, 6));
    std::cout << dl::repr(mm) << '\n';

    constexpr unsigned array[]{1, 2, 3, 4};
    std::cout << dl::repr(std::span{array}) << '\n';

    return 0;
}
