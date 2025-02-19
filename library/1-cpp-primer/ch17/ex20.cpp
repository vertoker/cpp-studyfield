#include <iostream>
#include <regex>
#include <string>

bool valid(const std::smatch& m)
{
    return m[1].matched;
}

int main()
{
    // For russian numbers - https://habr.com/ru/articles/110731/
    const std::string phonePattern = "^((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$";

    std::regex r(phonePattern);
    std::smatch m;
    std::string s;

    while (std::getline(std::cin, s))
    {
        bool validRecord = false;

        for (std::sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        {
            validRecord = true;
            if (valid(*it))
                std::cout << "valid phone: " << it->str() << std::endl;
            else std::cout << "invalid phone: " << it->str() << std::endl;
        }
        
        if (!validRecord)
            std::cout << "invalid record" << std::endl;
    }
    
    return 0;
}