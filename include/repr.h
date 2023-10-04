#pragma once

#include <string>
#include <format>
#include <type_traits>
#include <iterator>

namespace dl
{

template<typename T>
concept TriviallyRepresentable = std::is_fundamental_v<T> or
                                 std::is_same_v<T, char const*>;

// required iterator operations
template<typename Iterator>
concept IsIterator = requires(Iterator it)
{
    {*it};

    {++it} -> std::same_as<Iterator&>;
    {it++} -> std::same_as<Iterator>;
    {--it} -> std::same_as<Iterator&>;
    {it--} -> std::same_as<Iterator>;

    {it == it} -> std::same_as<bool>;
    {it != it} -> std::same_as<bool>;
};

// required iteratable functions
template<typename T>
concept IsIteratable = requires(T t)
{
    {t.begin()} -> IsIterator;
    {t.end()} -> IsIterator;
};

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

std::string repr(IsIteratable auto const& container)
{
    if (container.empty()) { return "[ (empty) ]"; } 
    std::string s{"[ "};
    {
        auto it{container.begin()};
        for (; it != std::prev(container.end()); ++it)
        {
            s+= repr(*it) + ", ";
        }
        s += repr(*it) + " ]";
    }
    return s;
}

} // namespace dl
