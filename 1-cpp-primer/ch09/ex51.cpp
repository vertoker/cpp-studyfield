#include <iostream>
#include <string>
#include <vector>

class Date
{
    unsigned year, month, day;

public:
    Date(const std::string& s)
    {
        // 1/1/1900
        if (s.find_first_of("/") != std::string::npos)
            setFormatNumeric(s);
        // January 1, 1900 -> Jan 1, 1900 -> Jan 1 1900
        else setFormatString(s);
    }

    void print()
    {
        std::cout << "day: " << day << ", month: " << month << ", year: " << year << std::endl;
    }

private:
    void setFormatNumeric(const std::string& s)
    {
        auto firstSlash = s.find_first_of('/');
        auto lastSlash = s.find_last_of('/');
        day = std::stoi(s.substr(0, firstSlash));
        month = std::stoi(s.substr(firstSlash + 1, lastSlash - firstSlash));
        year = std::stoi(s.substr(lastSlash + 1, 4));
    }
    void setFormatString(const std::string& s)
    {
             if (s.find("Jan") < s.size()) month =  1;
        else if (s.find("Feb") < s.size()) month =  2;
        else if (s.find("Mar") < s.size()) month =  3;
        else if (s.find("Apr") < s.size()) month =  4;
        else if (s.find("May") < s.size()) month =  5;
        else if (s.find("Jun") < s.size()) month =  6;
        else if (s.find("Jul") < s.size()) month =  7;
        else if (s.find("Aug") < s.size()) month =  8;
        else if (s.find("Sep") < s.size()) month =  9;
        else if (s.find("Oct") < s.size()) month = 10;
        else if (s.find("Nov") < s.size()) month = 11;
        else if (s.find("Dec") < s.size()) month = 12;

        const char* numbers = "1234567890";
        auto beginDay = s.find_first_of(numbers);
        auto endDay = s.find_first_not_of(numbers, beginDay + 1);
        auto beginYear = s.find_last_not_of(numbers) + 1;

        day = std::stoi(s.substr(beginDay, endDay - beginDay));
        year = std::stoi(s.substr(beginYear, 4));
    }
};

int main()
{
    Date d1("1/1/1900");
    Date d2("January 1, 1900");
    Date d3("Jan 1, 1900");
    Date d4("Jan 1 1900");

    d1.print();
    d2.print();
    d3.print();
    d4.print();

    return 0;
}