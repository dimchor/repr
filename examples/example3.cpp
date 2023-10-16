#include "../include/repr.h"

#include <iostream>
#include <numeric>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <tuple>
#include <optional>
#include <deque>
#include <forward_list>
#include <array>
#include <stack>
#include <queue>


void print(auto const c)
{
    std::cout << std::format("Is const?: {}\n{}\n", 
        std::is_const_v<decltype(c)>, 
        dl::repr(c));
}

auto mayhaps(bool b)
{
    return (b ? std::optional<std::string>{"Popsicle"} : std::nullopt);
}

/*
void print(auto c)
{
    std::cout << std::format("Is const?: {}\n{}\n", 
        std::is_const_v<decltype(c)>, 
        dl::repr(c));
}
*/

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
    print(v);

    std::set<int> set{};
    print(set);
    set.insert(9);
    print(set);

    std::map<int, int> m{};
    m[1] = 2;
    m[3] = 8;
    print(m);


    std::cout << dl::quoted(dl::repr(dl::quoted(m))) << '\n';

    std::cout << dl::repr(dl::quoted(std::make_pair(7, 8))) << '\n';

    std::cout << dl::repr(dl::quoted(std::make_tuple("float", 3.14, -8), '%')) 
        << '\n';

    std::cout << dl::repr(mayhaps(true)) << '\n';
    std::cout << dl::repr(mayhaps(false)) << '\n';

    std::deque<int> d{1, 2, 3, 4};
    print(d);

    std::forward_list<float> fl{1.1f, 2.2f, 3.3f, 4.4f};
    print(fl);


    std::list<bool> l{true, false, true, false};
    print(l);

    std::multiset<double> ms{1.2, 2.3, 3.4, 3.4};
     print(ms);


    std::multimap<int, int> mm{};
    print(mm);
    mm.insert(std::make_pair(1, 2));
    mm.insert(std::make_pair(3, 8));
    mm.insert(std::make_pair(3, 6));
    print(mm);

    constexpr unsigned array[]{1, 2, 3, 4};
    std::span sp{array};
    print(sp);

    std::stack<int> s{};
    print(s);
    s.push(1);
    s.push(2);
    print(s);

    std::queue<float> q{};
    print(q);
    q.push(1.1f);
    q.push(2.2f);
    q.push(3.3f);
    print(q);

    std::priority_queue<float> pq{};
    print(pq);
    pq.push(1.1f);
    pq.push(2.2f);
    pq.push(3.3f);
    print(pq);

    std::array<int, 4> cpp_array{1, 2, 3, 4};
    print(cpp_array);

    // initializer list test
    std::cout << dl::repr({1, 2, 3, 4, 5, 6, 7, 8}) << '\n';

    return 0;
}
