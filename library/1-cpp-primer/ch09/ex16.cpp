#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> v1 { 1, 2, 3 };
    std::list<int> l1 { 1, 2, 3 };

    std::cout << std::boolalpha;
    std::cout << (v1 == std::vector(l1.begin(), l1.end())) << std::endl;
    std::cout << std::noboolalpha;
    
    return 0;
}