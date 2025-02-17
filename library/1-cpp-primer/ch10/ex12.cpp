#include <../include/sales_data.h>
#include <vector>
#include <algorithm>

using std::move;

inline bool compare(const Sales_data& d1, const Sales_data& d2)
{
    return d1.isbn().size() < d2.isbn().size();
}

int main()
{
    Sales_data d1("12"), d2("1234"), d3("123"), d4("0"), d5("1239");
    std::vector<Sales_data> v { move(d1), move(d2), move(d3), move(d4), move(d5) };

    std::sort(v.begin(), v.end(), compare);

    for (const auto& el : v)
        std::cout << el.isbn() << " ";
    std::cout << std::endl;

    return 0;
}