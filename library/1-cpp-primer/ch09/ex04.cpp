#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator begin, std::vector<int>::iterator end, int toFind)
{
    while (begin != end)
    {
        if (*begin == toFind)
            return true;
        ++begin;
    }
    return false;
}

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };

    std::cout << std::boolalpha << find(v.begin(), v.end(), 3) << std::endl;
    std::cout << std::boolalpha << find(v.begin(), v.end(), 6) << std::endl;

    return 0;
}
