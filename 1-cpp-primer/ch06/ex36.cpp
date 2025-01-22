#include <string>

// wtf
std::string(&func(std::string(&arrStr)[10]))[10];

std::string (&func(std::string (&arrStr)[10]))[10]
{
    return arrStr;
}

int main()
{
    return 0;
}