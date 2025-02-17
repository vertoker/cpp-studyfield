#include <iostream>
#include <string>
#include <cstring>

void replaceAll(std::string& s, const std::string& oldVal, const std::string& newVal)
{
    for (size_t i = 0; i <= s.size() - oldVal.size(); )
    {
        if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal),
            i += newVal.size();
        }
        else ++i;
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