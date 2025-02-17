#include <../include/sales_data.h>
#include <vector>
#include <algorithm>

int main()
{
    using std::move;
    
    Sales_data d1("12"), d2("1234"), d3("123"), d4("0"), d5("1239");
    std::vector<Sales_data> v { move(d1), move(d2), move(d3), move(d4), move(d5) };

    std::sort(v.begin(), v.end(), [](const Sales_data& a, const Sales_data& b)
        { return a.isbn().size() < b.isbn().size(); });
    
    for (const auto& el : v)
        std::cout << el.isbn() << " ";
    std::cout << std::endl;

    return 0;
}