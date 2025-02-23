#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int>& vec)
{
    for (auto i : vec)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 3, 5 };

    print(v);
    auto it = std::remove(v.begin(), v.end(), 3);
    print(v);
    
    return 0;
}