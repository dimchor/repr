#include "../include/repr.h"

#include <iostream>

// fundamentals

int main()
{

    int a{5};

    std::cout << dl::repr(&a) << '\n';
    std::cout << dl::repr(nullptr) << '\n';
    std::cout << dl::repr(dl::quoted("null")) << '\n';
    std::cout << dl::repr(dl::quoted(3.14, '$')) << '\n';

    return 0;
}
