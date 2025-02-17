#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;// {1,2,3};

    int input;
    while (std::cin >> input)
        v.push_back(input);
    
    std::cout << "task 1" << std::endl;
    if (v.size() != 0)
    {
        for (auto it = v.begin() + 1; it != v.end(); ++it)
            std::cout << *it + *(it - 1) << ' ';
    }
    std::cout << std::endl;

    std::cout << "task 2" << std::endl;
    if (v.size() != 0)
    {
        auto begin = v.begin(), end = v.end();
        while (end - begin > 1)
        {
            --end;
            std::cout << *begin + *end << ' ';
            ++begin;
        }
        if (v.size() % 2 == 1)
            std::cout << *(begin) << ' ';
        std::cout << std::endl;
    }
    
    return 0;
}