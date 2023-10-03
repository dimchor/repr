#pragma once

#include <string>
#include <format>
#include <type_traits>

namespace dl
{

template<typename T, 
    std::enable_if_t<std::is_fundamental<T>::value, bool> = true>
std::string repr(T const obj)
{
    return std::format("{}", obj);
}

std::string repr(std::nullptr_t);

std::string repr(char const*);

std::string repr(void const*);

std::string repr(std::string const&);

std::string quoted(auto const& obj, char type = '\"')
{
    return std::format("{:c}{}{:c}", type, repr(obj), type);
}

} // namespace dl
