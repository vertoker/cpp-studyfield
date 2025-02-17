#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s; // not a literal type
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl; // false
}