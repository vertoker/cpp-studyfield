#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool LessOrEqual(const std::string& s, std::string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::vector<std::string> v { "vertoker", "abcd", "qwertyuiop", "zxcvb", "asdf" };
    std::cout << std::count_if(v.cbegin(), v.cend(), std::bind(LessOrEqual, std::placeholders::_1, 6));
    return 0;
}