#include <iostream>
#include <string>
#include <format>

#include "../include/repr.h"

class Representable
{
public:
    Representable(int x): _x(x) {}

    std::string repr() const
    {
        return std::format("{}", _x);
    }
private:
    int _x{};
};

class NonRepresentable{};

int main()
{
    std::cout << dl::repr(Representable{5}) << '\n';
    // compiler error
    // std::cout << dl::repr(NonRepresentable{}) << '\n';

    return 0;
}
