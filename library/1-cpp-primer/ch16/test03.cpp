#include <tuple>
#include <iostream>

template <typename... Types>
std::tuple<Types...> f(Types... args)
{
    std::tuple<Types...> result(args...);
    return result;
}

template<typename T>
std::ostream& print(std::ostream& os, const T& what)
{
	return os << what;
}

template<typename T, typename... Types>
std::ostream& print(std::ostream& os, const T& what, const Types&... other)
{
	return print(os << what << ' ', other...);
}
