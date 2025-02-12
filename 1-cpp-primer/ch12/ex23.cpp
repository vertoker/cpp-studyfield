#include <iostream>
#include <string>
#include "string.h"

int main()
{
    // c string
    char* constr = new char[strlen("hello " "world") + 1];
    strcat(constr, "hello ");
    strcat(constr, "world");
    std::cout << constr << std::endl;
    delete[] constr;

    // std::string
    std::string str1{"hello "}, str2{"world"};
    std::cout << str1 + str2 << std::endl;

    return 0;
}