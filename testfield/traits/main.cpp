// https://en.cppreference.com/w/cpp/types/enable_if.html

#include <iostream>
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void print(T num)
{
    std::cout << num;
}

int main()
{
    int i = 5;
    print(i);
    return 0;
}