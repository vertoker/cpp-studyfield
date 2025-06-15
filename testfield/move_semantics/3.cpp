#include <iostream>
#include <vector>


// Metapocalypse

template<typename T>
struct RemoveReference { using type = T; };
template<typename T>
struct RemoveReference<T&> { using type = T; };
template<typename T>
struct RemoveReference<T&&> { using type = T; };

template<typename T>
using RemoveReferenceT = typename RemoveReference<T>::type;


// My own move and forward

template <typename T>
std::remove_reference_t<T>&& move(T&& value)
    { return static_cast<std::remove_reference_t<T>&&>(value); }

template <typename T>
T&& forward(std::remove_reference_t<T>&& value)
{
    static_assert(!std::is_lvalue_reference_v<T>);
    return static_cast<T&&>(value);
}


// Code

void foo(int& x) { std::cout << "int&" << std::endl; }
void foo(int&& x) { std::cout << "int&&" << std::endl; }

template <typename T>
void bar(T&& x)
{
    foo(forward<T>(5));
}


int main()
{
    int x = 10;
    
    //bar(x);
    bar(5);
    std::cout << std::endl;

    foo(std::move(x));
    foo(std::forward<int>(x));
    std::cout << std::endl;

    foo(move(x));
    foo(move(5));

    return 0;
}