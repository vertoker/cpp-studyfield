#include <iostream>
#include <vector>

void print(const std::vector<int>& vec, int startIndex = 0)
{
    if (startIndex < vec.size())
    {
        std::cout << vec[startIndex] << std::endl;
        print(vec, startIndex + 1);
    }
}

int main()
{
    std::vector<int> vec {1, 2, 3, 4};
    print(vec);
    return 0;
}
