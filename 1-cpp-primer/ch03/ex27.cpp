#include <iostream>

int txt_size()
{
    return 32;
}

int main()
{
    unsigned buf_size = 1024;

    int a[buf_size]; // ok, compiler know about value in `buf_size`
    int b[4 * 7 - 14]; // ok, compiler evaluate value from literal expression
    int c[txt_size()]; // ok, compiler know about value from `txt_size`
    // char d[11] = "fundamental"; // not ok, not enough space for '/0'

    return 0;
}