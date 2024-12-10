#include <iostream>

int main()
{
    int i = 0;

    // double *pd = &i; // not matching types, int* != double*
    // int *pi = i; // can't set rvalue into pointer
    int *pi = &i; // get address of variable, value => address value

    return 0;
}