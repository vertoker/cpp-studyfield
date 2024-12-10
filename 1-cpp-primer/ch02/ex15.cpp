#include <iostream>

int main()
{
    int ival = 1.01; // standard lvalue and rvalue
    //int& rval1 = 1.01; // 1.01 is not lvalue
    int& rval2 = ival; // ival is lvalue
    //int& rval3; // reference always requires initializer
    
    return 0;
}