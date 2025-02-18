#include <iostream>

template <typename Printable>
std::ostream& print(std::ostream& os, const Printable& printable)
{
    return os << printable;
}
template <typename Printable, typename... Args>
std::ostream& print(std::ostream& os, const Printable& printable, const Args&... rest)
{
    return print(os << printable << ", ", rest...);
}

int main()
{
    print(std::cout, 1) << std::endl;
    return 0;
}