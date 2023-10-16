# repr - a C++ implementation of Python's repr()

`repr()` allows you to easily convert any* type into a `std::string`

## *Supported types and containers
- Primitives: `int`, `float`, `double`, etc.
- Pointers (prints the address it points to)
- Containers, specifically:
    - `std::array`,
    - `std::vector`,
    - `std::deque`,
    - `std::list`,
    - `std::forward_list`,
    - `std::set`,
    - `std::map`,
    - `std::multiset`,
    - `std::multimap`.
- Container adapters, specifically:
    - `std::stack` (prints `top()`),
    - `std::queue` (prints `front()` and `back()`),
    - `std::priority_queue` (prints `top()`).
- Memory:
    - `std::unique_ptr`
    - `std::shared_ptr`
    - `std::weak_ptr`
- Other:
    - `std::pair`,
    - `std::tuple`,
    - `std::span`,
    - C-style arrays (using `std::span`).
    - `std::byte`
    - `std::initializer_list`

## Other features
- Custom type support, by adding `repr()` as a public method in your class.
- `quoted()`, which just adds quotes to the string (I'm not sure why this 
exists, but there you go.)

## Requirements
- C++20
