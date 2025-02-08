#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec { 1, 1, 2, 2, 3, 3, 4, 4, 5 };
    std::vector<int> vec2;
    vec2.reserve(vec.size());

    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    
    for (auto i : vec2)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}