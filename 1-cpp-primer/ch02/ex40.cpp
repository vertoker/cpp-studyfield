#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned unitsSold;
    double revenue;
} data1, data2, *data3; // why I can do this

int main()
{
    return 0;
}