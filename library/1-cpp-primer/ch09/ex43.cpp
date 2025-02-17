#include <iostream>
#include <string>

void replaceAll(std::string& s, const std::string& oldVal, const std::string& newVal)
{
    for (auto current = s.begin(); current <= s.end() - oldVal.size(); )
    {
        if (oldVal == std::string{ current, current + oldVal.size() })
        {
            current = s.erase(current, current + oldVal.size());
            current = s.insert(current, newVal.begin(), newVal.end());
            current += newVal.size();
        }
        else ++current;
    }
}

int main()
{
    std::string s { "123 thru 456 tho" };
    replaceAll(s, "tho", "through");
    replaceAll(s, "thru", "through");
    std::cout << s << std::endl;

    return 0;
}