#include "../include/repr.h"

#include <iostream>
#include <cstddef>

// other types

int main()
{

    int a{5};

    std::cout << dl::repr(&a) << '\n';
    std::cout << dl::repr(nullptr) << '\n';
    std::cout << dl::repr("null") << '\n';
    std::cout << dl::repr(dl::quoted("null")) << '\n';
    std::cout << dl::repr(dl::quoted(3.14, '$')) << '\n';

    std::cout << dl::repr(std::byte{0b11111000}) << '\n';
    std::cout << dl::repr(std::byte{0b10101010}) << '\n';

    return 0;
}
