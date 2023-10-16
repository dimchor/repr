#include "../include/repr.h"

#include <iostream>
#include <cstddef>
#include <any>
#include <complex>

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

    std::any b = 42;
    std::cout << dl::repr<int>(b) << '\n';

    using namespace std::complex_literals;

    std::complex<double> z{1.0 - 4i};
    std::cout << dl::repr(z) << '\n';

    return 0;
}
