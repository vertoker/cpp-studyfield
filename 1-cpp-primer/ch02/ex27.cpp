#include <iostream>

int main()
{
    int i = -1; // regular
    // int& r = 0; // 0 is not lvalue 

    int* const p2 = &i; // const pointer to non-const value

    const int i2 = -1; // regular
    // int& r = 0; // 0 is not lvalue

    const int* const p3 = &i2; // const pointer to const value

    const int* p1 = &i2; // non-const pointer to const value

    // const int& const r2; // const reference to const type doesn't have initializer

    const int i3 = i; // copy constructor
    const int& r = i; // non-const reference to const type is ok with usual i
    
    return 0;
}