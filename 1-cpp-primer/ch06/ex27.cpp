#include <iostream>
#include <initializer_list>

int sum(std::initializer_list<int> params)
{
    int sum = 0;
    for (const int* beg = params.begin(); beg != params.end(); ++beg)
        sum += *beg;
    return sum;
}

int main()
{
    std::cout << sum({1, 2, 3, 4}) << std::endl;
    return 0;
}