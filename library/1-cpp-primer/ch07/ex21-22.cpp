#include <iostream>
#include <string>

// TODO 7.12

struct Sales_data
{
    friend std::istream& read(std::istream& is, Sales_data& item);
    friend std::ostream& print(std::ostream& os, const Sales_data& item);

public:
    Sales_data() = default;
    Sales_data(const std::string& bookNo) : bookNo(bookNo) { }
    Sales_data(const std::string& bookNo, const unsigned units_sold, const double revenue) 
        : bookNo(bookNo), units_sold(units_sold), revenue(revenue) { }
    Sales_data(std::istream& is) { read(is, *this); }

    Sales_data& combine(const Sales_data& other);
    inline std::string isbn() const { return bookNo; }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& other)
{
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
std::ostream& print(std::ostream& os, const Sales_data& item) // const because it only readed
{
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}
Sales_data sum(const Sales_data& a, const Sales_data& b)
{
    Sales_data sum = a;
    sum.combine(b);
    return sum;
}

int main()
{
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
            if (total.isbn() == trans.isbn())
                total = sum(total, trans);
            else
            {
                print(std::cout, total);
                total = trans;
            }
        }
        print(std::cout, total);
    }
    else
    {
        std::cerr << "No data" << std::endl;
        return -1;
    }
    return 0;
}