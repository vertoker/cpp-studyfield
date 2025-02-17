#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::istream& print(std::istream& is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istringstream iss("hi 1 2 3");
    print(iss);
    return 0;
}
