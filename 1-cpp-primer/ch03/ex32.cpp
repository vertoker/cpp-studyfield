#include <iostream>
#include <vector>

int main()
{
    size_t array_size = 10;
    int sa[array_size]; // source array
    std::vector<int> sv; // source vector
    sv.reserve(array_size);

    for (size_t i = 0; i < array_size; i++)
    {
        sa[i] = i + 1;
        sv.push_back(i + 1);
    }

    // copy into array
    int da[array_size]; // destination array

    for (size_t i = 0; i < array_size; i++)
        da[i] = sa[i];
    
    // copy into vector
    std::vector<int> dv; // destination vector
    dv.reserve(array_size);

    for (size_t i = 0; i < array_size; i++)
        dv.push_back(sv[i]);
    
    // print check
    std::cout << "sa" << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << sa[i] << ' ';
    std::cout << std::endl;
    
    std::cout << "sv" << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << sv[i] << ' ';
    std::cout << std::endl;
    
    std::cout << "da" << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << da[i] << ' ';
    std::cout << std::endl;
    
    std::cout << "dv" << std::endl;
    for (size_t i = 0; i < array_size; i++)
        std::cout << dv[i] << ' ';
    std::cout << std::endl;
    

    return 0;
}