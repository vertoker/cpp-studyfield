#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <string>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5 };
    std::list<std::string> l { "1", "2", "3", "4", "5" };

    std::cout << std::count(v.cbegin(), v.cend(), 3) << std::endl;
    std::cout << std::count(l.cbegin(), l.cend(), "3") << std::endl;

    return 0;
}