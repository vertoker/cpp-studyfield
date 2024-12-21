#include <iostream>

int main()
{
    char cval;
    int ival;
    unsigned int uival;
    float fval;
    double dval;

    cval = 'a' + 3; // char -> int
    fval = uival - ival * 1.0; // ival -> double, mult, uival -> float, (ival * 1.0) -> float, substract
    dval = uival * fval; // uival -> float, mult, float -> double
    cval = ival + fval + dval; // ival -> float, sum, fval -> double, sum, double -> char
    
    return 0;
}