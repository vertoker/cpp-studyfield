#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool Less(const std::string& s, size_t sz)
{
    return s.size() < sz;
}

int main()
{
    using namespace std::placeholders;
    std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7 };
    std::string str = "2345";
    
    auto result = std::find_if(vec.begin(), vec.end(), std::bind(Less, str, _1));
    if (result != vec.end())
        std::cout << *result << std::endl;
    
    return 0;
}