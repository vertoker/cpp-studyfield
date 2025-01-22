#include <iostream>
#include <string>

bool str_subrange(const std::string& str1, const std::string& str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i)
        if (str1[i] != str2[i])
            return false; // error was here
    
    return true; // error was here
}


int main()
{
    std::string s1 = "Hi";
    std::string s2 = "Hi2";

    std::cout << (str_subrange(s1, s2) ? "true" : "false") << std::endl;
    return 0;
}