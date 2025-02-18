#include <iostream>
#include <string>
#include <functional>
#include <type_traits>
#include <cstdint>

// #1
class Class{};

void print()
{
    std::cout << std::is_floating_point_v<Class> << std::endl;
    std::cout << std::is_floating_point_v<float> << std::endl;
    std::cout << std::is_floating_point_v<int> << std::endl;
}

// #2
template <typename T>
class Data
{
    static_assert(std::is_signed_v<T>, "Must be signed");
};

// #3
void f_signed(int i) { }
void f_unsigned(unsigned u) { }

template <typename T>
void f(T t)
{
    // if constexpr only starts with C++17
    if constexpr(std::is_signed_v<T>)
        f_signed(t);
    else if constexpr(std::is_unsigned_v<T>)
        f_unsigned(t);
    else static_assert(std::is_signed_v<T> || std::is_unsigned_v<T>, "Must be signed or unsigned");
}

int main()
{
    print();

    Data<int> d1;
    // Data<unsigned> d2;

    f(1);
    f(1U);
    // f(1.0);

    return 0;
}