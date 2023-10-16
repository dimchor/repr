#pragma once

#include <string>
#include <format>
#include <type_traits>
#include <iterator>
#include <tuple>
#include <optional>
#include <utility>
#include <stack>
#include <queue>
#include <memory>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <any>

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
concept HasReprMethod = requires(T const& t)
{
    {t.repr()} -> std::same_as<std::string>;
};

std::string repr(TriviallyRepresentable auto const&);
std::string repr(IsIteratable auto const&);
template<typename T1, typename T2>
std::string repr(std::pair<T1, T2> const&);
template<typename... Args>
std::string repr(std::tuple<Args...> const&);
std::string repr(IsIteratable auto const&);
template<typename T>
std::string repr(std::stack<T> const&);
template<typename T>
std::string repr(std::queue<T> const&);
template<typename T>
std::string repr(std::priority_queue<T> const&);
template<typename T>
std::string repr(std::unique_ptr<T> const&);
template<typename T>
std::string repr(std::shared_ptr<T> const&);
template<typename T>
std::string repr(std::weak_ptr<T> const&);
template<typename T>
std::string repr(std::initializer_list<T>);
std::string quoted(auto const&, char = '\"');
template<typename T>
std::string repr(std::optional<T>);

std::string repr(std::nullptr_t);
std::string repr(void const*);
std::string const& repr(std::string const&);
std::string repr(std::byte);

std::string repr(TriviallyRepresentable auto const& obj)
{
    return std::format("{}", obj);
}

template<typename T1, typename T2>
std::string repr(std::pair<T1, T2> const& pair)
{
    return std::format("( {}, {} )", pair.first, pair.second);
}

template<typename... Args>
std::string repr(std::tuple<Args...> const& tuple)
{
    if (sizeof...(Args) < 1) { return "( (empty) )"; }
    std::string s{"( "};
    std::apply(
        [&s] (Args const&... args)
        {
            std::size_t n{};
            (( s+= repr(args) + (++n != sizeof...(Args) ? ", " : " )")), ...);
        },
        tuple
    );
    return s;
}

template<typename T>
std::string repr(std::stack<T> const& stack)
{
    if (stack.empty()) { return "(empty)"; }
    return std::format("top(): {}", stack.top());
}

template<typename T>
std::string repr(std::queue<T> const& queue)
{
    if (queue.empty()) { return "(empty)"; }
    return std::format("front(): {}, back(): {}", queue.front(), queue.back());
}

template<typename T>
std::string repr(std::priority_queue<T> const& priority_queue)
{
    if (priority_queue.empty()) { return "(empty)"; }
    return std::format("top(): {}", priority_queue.top());
}

std::string repr(IsIteratable auto const& container)
{
    if (container.empty()) { return "[ (empty) ]"; } 
    std::string s{"[ "};
    {
        long int n{};
        long int const size{ // always positive since we start from begin()
            std::distance(container.begin(), container.end())};
        for (auto it{container.begin()}; it != container.end(); ++it)
        {
            s+= repr(*it) + (++n != size ? ", " : " ]");
        }
    }
    return s;
}

std::string repr(HasReprMethod auto const& obj)
{
    return obj.repr();
}

template<typename T>
std::string repr(std::unique_ptr<T> const& u_ptr)
{
    return repr(u_ptr.get());
}

template<typename T>
std::string repr(std::shared_ptr<T> const& u_ptr)
{
    return repr(u_ptr.get());
}

template<typename T>
std::string repr(std::weak_ptr<T> const& u_ptr)
{
    return repr(u_ptr.get());
}

template<typename T>
std::string repr(std::initializer_list<T> l)
{
    return repr(std::vector<T>{std::move(l)});
}

template<typename T>
std::string repr(std::optional<T> o)
{
    return (o.has_value() ? repr(*o) : "std::nullopt");
}

template<typename T>
std::string repr(std::any const& a)
{
    return (a.has_value() ? repr(std::any_cast<T>(a)) : "any: no value");
}

std::string quoted(auto const& obj, char delim)
{
    return std::format("{:c}{}{:c}", delim, repr(obj), delim);
}

} // namespace dl
