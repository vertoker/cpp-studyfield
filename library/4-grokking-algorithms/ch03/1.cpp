#include <iostream>
#include <string>

void greet2(const std::string& name)
{
    std::cout << "state program is here, name is " << name << std::endl;
}

void greet(const std::string& name)
{
    greet2(name);
}

int main()
{
    greet("maggie");
    return 0;
}