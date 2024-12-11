#include <iostream>

int main()
{
    int null = 0; // ok, `null` is not reserved name
    // int* p = null; // can't set to pointer lvalue, must place &
    int* p = &null;
    
    return 0;
}