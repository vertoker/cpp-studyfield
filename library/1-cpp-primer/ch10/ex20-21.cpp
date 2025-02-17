#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // ex20
    std::vector<int> v { 1, 2, 3, 4, 5 };
    auto size = std::count_if(v.begin(), v.end(), [](int item) { return item % 2 == 1; });
    std::cout << size << std::endl;

    // ex21
    int i = 7;
    auto predicate = [&i](){ return --i ? false : true; };
    while (!predicate())
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}