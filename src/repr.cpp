#include "../include/repr.h"

namespace dl
{

std::string repr(std::nullptr_t null)
{
    return "nullptr";
}

std::string repr(void const* ptr)
{
    return std::format("{}", ptr);
}

std::string const& repr(std::string const& cpp_string)
{
    return cpp_string;
}

std::string repr(std::byte b)
{
    auto uc{static_cast<unsigned char>(b)};
    std::string output{};
    for (std::uint8_t i{}; i < 8; ++i)
    {
        output += (uc & 128 ? '1' : '0');
        uc <<= 1;
    }
    return output;
}

} // namespace dl
