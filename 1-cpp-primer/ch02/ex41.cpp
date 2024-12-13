#include <iostream>
#include <string>

int main()
{
    struct Sales_data {
        std::string bookNo;
        unsigned unitsSold;
        double revenue;
    } data1, data2;

    double price = 0;

    // Input
    std::cin >> data1.bookNo >> data1.unitsSold >> price;
    data1.revenue = data1.unitsSold * price;
    std::cin >> data2.bookNo >> data2.unitsSold >> price;
    data2.revenue = data2.unitsSold * price;

    // Output
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCount = data1.unitsSold + data2.unitsSold;
        double totalRevenue = data1.revenue + data2.revenue;

        std::cout << data1.bookNo << " " << totalCount << " " << totalRevenue << " ";

        if (totalCount != 0)
            std::cout << totalRevenue / totalCount << std::endl;
        else std::cout << "(no sales)" << std::endl;
    }
    else
    {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }

    return 0;
}