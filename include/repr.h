#pragma once

#include <string>
#include <format>
#include <type_traits>

namespace dl
{

template<typename T>
concept TriviallyRepresentable = std::is_fundamental_v<T> or
                                 std::is_same_v<T, char const*>;

template<typename T>
std::string repr(T const obj) requires TriviallyRepresentable<T>
{
    return std::format("{}", obj);
}

std::string repr(std::nullptr_t);

std::string repr(void const*);

std::string const& repr(std::string const&);

std::string quoted(auto const& obj, char delim = '\"')
{
    return std::format("{:c}{}{:c}", delim, repr(obj), delim);
}

} // namespace dl
