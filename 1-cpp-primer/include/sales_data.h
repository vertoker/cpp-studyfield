#ifndef SALES_DATA_HPP
#define SALES_DATA_HPP

#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned unitsSold = 0;
    double revenue = 0.0;
};

#endif