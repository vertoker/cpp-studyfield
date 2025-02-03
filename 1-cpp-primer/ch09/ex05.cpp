#include <iostream>
#include <vector>

std::vector<int>::iterator find(std::vector<int>::iterator begin, std::vector<int>::iterator end, int toFind)
{
    while (begin != end)
    {
        if (*begin == toFind)
            return begin;
        ++begin;
    }
    return begin;
}

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };

    std::cout << std::boolalpha << ( find(v.begin(), v.end(), 3) != v.end() ) << std::endl;
    std::cout << std::boolalpha << ( find(v.begin(), v.end(), 6) != v.end() ) << std::endl;

    return 0;
}
