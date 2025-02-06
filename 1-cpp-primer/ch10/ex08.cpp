#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> // back_inserter - part of iterator

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };
    std::fill_n(std::back_inserter(v), 5, 0);

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}