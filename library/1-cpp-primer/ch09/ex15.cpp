#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1 { 1, 2, 3 };
    std::vector<int> v2 { 1, 2, 3 };
    std::vector<int> v3 { 1, 2 };

    std::cout << std::boolalpha;
    std::cout << (v1 == v2) << std::endl;
    std::cout << (v1 == v3) << std::endl;
    std::cout << std::noboolalpha;
    
    return 0;
}