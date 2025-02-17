#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    
    std::fill(vec.begin(), vec.end(), 0);
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::fill_n(vec.begin(), vec.size(), 1);
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}