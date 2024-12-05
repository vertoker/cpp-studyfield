#include <iostream>

// reference to ex11.cpp
int main()
{
    int start, end;
    std::cout << "Enter range.start: " << std::flush;
    std::cin >> start;
    std::cout << "Enter range.end: " << std::flush;
    std::cin >> end;

    if (end < start)
        std::swap(start, end);

    for (int i = start; i <= end; ++i)
        std::cout << i << std::endl;
    return 0;
}