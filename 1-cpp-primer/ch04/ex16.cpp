#include <iostream>

int ival;

int* getPtr()
{
    return &ival;
}

int main()
{
    bool p;
    if (p = getPtr() != 0); // this is valid
    if ( p = ( getPtr() != 0 ) ) // with that order of execution

    int i = 0;
    // if (i = 1024); // incorrect

    int i2 = 1024;
    if (i2 == 1024); // this is how should be

    return 0;
}