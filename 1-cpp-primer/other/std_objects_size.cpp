#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string s1, s2 = "Hello";
    std::cout << "std::string : s1=" << sizeof(s1) << ", s2=" << sizeof(s2) << std::endl;
    return 0;
}