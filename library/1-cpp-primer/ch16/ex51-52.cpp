#include <iostream>

template <typename T, typename ...Args>
void foo(T t, Args ...args)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(args) << std::endl;
}

int main()
{
    foo(1, 2);
    foo(1, 2, 3, 4, 5, 6);
    
    return 0;
}