#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item current, overall;

    if (std::cin >> overall)
    {
        while (std::cin >> current)
        {
            if (current.isbn() == overall.isbn())
            {
                overall += current;
            }
            else
            {
                break;
            }
        }
        std::cout << overall << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Incorrect data" << std::endl;
        return -1;
    }
}