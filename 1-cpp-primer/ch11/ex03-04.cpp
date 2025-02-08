#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

std::map<std::string, std::size_t> count()
{
    std::map<std::string, std::size_t> counts;
    for (std::string w; std::cin >> w; ++counts[w]);
    return counts;
}

std::string strip(std::string& str)
{
    for (auto& ch : str)
        ch = std::tolower(ch);
    str.erase(std::remove_if(str.begin(), str.end(), ispunct), str.end());
    return str;
}

std::map<std::string, std::size_t> strip_and_count()
{
    std::map<std::string, std::size_t> counts;
    for (std::string w; std::cin >> w; ++counts[strip(w)])
    return counts;
}

void print(const std::map<std::string, std::size_t>& m)
{
    for (const auto& kv : m)
        std::cout << kv.first << " : " << kv.second << std::endl;
}

int main()
{
    // ex03
    print(count());
    std::cin.clear();

    // ex04
    print(strip_and_count());

    return 0;
}