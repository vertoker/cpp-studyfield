#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;// {1,2,3};

    int input;
    while (std::cin >> input)
        v.push_back(input);
    
    std::cout << "task 1" << std::endl;
    for (size_t i = 1; i < v.size(); ++i)
        std::cout << v[i] + v[i - 1] << ' ';
    std::cout << std::endl;

    std::cout << "task 2" << std::endl;
    auto size = v.size();
    if (size != 0)
    {
        size_t halfSize = size / 2;

        for (size_t i = 0; i != halfSize; ++i)
            std::cout << v[i] + v[size - i - 1] << ' ';
        if (size % 2 == 1)
            std::cout << v[halfSize] << ' ';
        std::cout << std::endl;
    }
    
    return 0;
}