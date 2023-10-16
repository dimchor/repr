#include <iostream>
#include <memory>

#include "../include/repr.h"

int main()
{
    auto u_ptr{std::make_unique<int>(8)};

    std::cout << dl::repr(u_ptr) << '\n';
    std::cout << dl::repr(*u_ptr) << '\n';

    auto s_ptr{std::make_shared<int>(16)};

    std::cout << dl::repr(s_ptr) << '\n';
    std::cout << dl::repr(*s_ptr) << '\n';

    auto w_ptr{s_ptr};
    std::cout << dl::repr(w_ptr) << '\n';
    std::cout << dl::repr(*w_ptr) << '\n';
    
    return 0;
}
