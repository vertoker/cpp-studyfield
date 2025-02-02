#include <iostream>
#include <string>

bool lengthCompare(const std::string& s1, const std::string& s2)
{
    std::cout << "compare " << s1 << " and " << s2 << std::endl;
    return true;
}

void overhead(const std::string& s1, const std::string& s2, bool (*pf)(const std::string&, const std::string&))
{
    pf(s1, s2);
}

bool (*pf)(const std::string&, const std::string&);

int main()
{
    pf = &lengthCompare;
    
    lengthCompare("1", "1");
    pf("2", "2");

    overhead("3", "3", lengthCompare);
    overhead("4", "4", &lengthCompare);
    overhead("5", "5", pf);
    overhead("6", "6", *pf);

    pf = nullptr;

    return 0;
}