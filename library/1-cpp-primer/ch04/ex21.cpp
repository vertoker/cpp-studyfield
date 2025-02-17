#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec {1, 2, 3, 4, 5};

    for (auto& n : vec)
        n = (n % 2 == 1) ? n * 2 : n;
    
    for (const auto& n : vec)
        std::cout << n << ' ';
    std::cout << std::endl;
    
    return 0;
}