#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    inline std::string isbn() const;
    Sales_data& combine(const Sales_data& other);
};

inline std::string Sales_data::isbn() const
{
    return bookNo + " " + std::to_string(units_sold) + " " + std::to_string(revenue);
}
Sales_data& Sales_data::combine(const Sales_data& other)
{
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *this;
}

int main()
{
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.bookNo == trans.bookNo)
                total.combine(trans);
            else
            {
                std::cout << total.isbn() << std::endl;
                total = trans;
            }
        }
        std::cout << total.isbn() << std::endl;
    }
    else
    {
        std::cerr << "No data" << std::endl;
        return -1;
    }
    return 0;
}