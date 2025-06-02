#include "stdafx.h"

int main()
{
    const int count = 4;
    std::array<int, count> input;
    
    for (size_t i = 0; i < count; i++)
        std::cin >> input[i];
    
    int sum = std::accumulate(input.begin(), input.end(), 0);
    std::cout << "Sum of input is " << sum;
    
    int sum2 = head::sum(sum, 666);
    std::cout << "Sum 2 of input is " << sum;

    return 0;
}