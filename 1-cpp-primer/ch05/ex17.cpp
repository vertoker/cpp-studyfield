#include <iostream>
#include <vector>

bool equals(std::vector<int>& vec1, std::vector<int>& vec2)
{
    auto minLength = std::min(vec1.size(), vec2.size());

    for (size_t index = 0; index < minLength; ++index)
        if (vec1[index] != vec2[index])
            return false;
    
    return true;
}

int main()
{
    std::vector<int> vec1 {0, 1, 1, 2};
    std::vector<int> vec2 {0, 1, 1, 2, 3, 5, 8};
    std::cout << (equals(vec1, vec2) ? "true" : "false") << std::endl;

    return 0;
}