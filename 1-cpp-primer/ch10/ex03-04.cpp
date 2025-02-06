#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v1 { 1, 2, 3, 4, 5 };
    std::vector<double> v2 { 1, 2, 3, 4, 5 };

    std::cout << std::accumulate(v1.begin(), v1.end(), 0) << std::endl;
    std::cout << std::accumulate(v2.begin(), v2.end(), 0) << std::endl;

    return 0;
}