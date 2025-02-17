#include <iostream>

int main()
{
    const int rowLen = 3;
    const int colLen = 4;
    int ia[rowLen][colLen] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::cout << "version 1" << std::endl;
    for (const auto& row : ia)
    {
        for (const auto& col : row)
            std::cout << col << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "version 2" << std::endl;
    for (int i = 0; i < rowLen; ++i)
    {
        for (int j = 0; j < colLen; ++j)
            std::cout << ia[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "version 3" << std::endl;
    auto* e1 = ia + rowLen;
    for (auto* p1 = ia; p1 != e1; ++p1)
    {
        auto* e2 = *p1 + colLen;
        for (auto* p2 = *p1; p2 != e2; ++p2)
            std::cout << *p2 << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}