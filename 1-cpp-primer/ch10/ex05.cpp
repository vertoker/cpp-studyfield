#include <iostream>
#include <algorithm>

int main()
{
    const char* s1 = "Hello";
    const char* s2 = "Hello";

    std::cout << std::equal(s1, s2) << std::endl;
    
    return 0;
}