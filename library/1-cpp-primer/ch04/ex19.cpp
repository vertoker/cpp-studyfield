#include <iostream>
#include <vector>

int main()
{
    int ival = 0;
    int* ptr = &ival;
    std::vector<int> vec {1, 2, 3};

    // ptr != 0 && *ptr++
    if (ptr != nullptr && *ptr++)
        std::cout << "a correct" << std::endl;
    
    // ival++ && ival
    if (ival && ival + 1)
        std::cout << "b correct" << std::endl;
    
    // vec[ival++] <= vecp[ival]
    if (vec[ival] <= vec[ival + 1])
        std::cout << "c correct" << std::endl;
    
    return 0;
}