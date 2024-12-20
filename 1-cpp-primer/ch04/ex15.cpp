#include <iostream>

int main()
{
    double dval;
    int ival;
    int* pval;

    // dval = ival = pval = 0; // can't set pointer with rvalue
    dval = ival = 0; // correct
    
    return 0;
}