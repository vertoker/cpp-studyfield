#include <iostream>

int main()
{
    int start, end;
    std::cout << "Enter range.start: " << std::flush;
    std::cin >> start;
    std::cout << "Enter range.end: " << std::flush;
    std::cin >> end;

    if (end < start)
        std::swap(start, end);

    int counter = start;
    while (counter <= end)
    {
        std::cout << counter << std::endl;
        ++counter;
    }
    return 0;
}