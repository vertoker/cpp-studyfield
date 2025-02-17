#include <iostream>
#include "../include/Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total) {
        Sales_item current;
        while (std::cin >> current)
        {
            if (current.isbn() == total.isbn())
            {
                total += current;
            }
            else
            {
                std::cout << "Total: " << total << std::endl;
                total = current;
            }
        }
        std::cout << "Total: " << total << std::endl;
    }
    else {
        std::cerr << "Incorrect data" << std::endl;
        return -1;
    }
    return 0;
}