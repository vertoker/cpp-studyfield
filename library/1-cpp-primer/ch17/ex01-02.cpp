#include <iostream>
#include <tuple>
#include <string>
#include <vector>

int main()
{
    std::tuple<int, int, int> t1 = std::make_tuple(10, 20, 30);
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> t2;
    
    return 0;
}