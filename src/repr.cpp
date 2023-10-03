#include "../include/repr.h"

namespace dl
{

std::string repr(std::nullptr_t null)
{
    return "nullptr";
}

std::string repr(char const* c_string)
{
    return std::format("{}", c_string);
}

std::string repr(void const* ptr)
{
    return std::format("{}", ptr);
}

std::string repr(std::string const& cpp_string)
{
    return cpp_string;
}

} // namespace dl

