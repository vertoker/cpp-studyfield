#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    
    std::cout << v.at(0); // error - std::out_of_range
    std::cout << v[0]; // segfault
    std::cout << v.front(); // segfault
    std::cout << v.back(); // segfault

    return 0;
}