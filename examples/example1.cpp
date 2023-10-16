#include "../include/repr.h"

#include <iostream>

// fundamentals

int main()
{
    std::cout << dl::repr(-1) << '\n';
    std::cout << dl::repr(1) << '\n';
    std::cout << dl::repr(1.9f) << '\n';
    std::cout << dl::repr(1.6) << '\n';

    int a{5};

    std::cout << dl::repr(a) << '\n';

    std::cout << dl::repr(18446744073709551615) << '\n';

    std::cout << dl::repr(true) << '\n';
    std::cout << dl::repr(false) << '\n';

    return 0;
}
