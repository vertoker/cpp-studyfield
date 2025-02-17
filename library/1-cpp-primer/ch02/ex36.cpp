#include <iostream>

int main()
{
    int a = 3, b = 5;
    decltype(a) c = a; // int
    decltype((b)) d = a; // int&
    
    ++c; // c = 4, a = 3
    ++d; // a = 4

    std::cout << a << " " << b << " " << c << " " << d << std::endl; // 4 5 4 4

    return 0;
}