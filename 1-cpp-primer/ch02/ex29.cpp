#include <iostream>

int main()
{
    int i = 1;
    const int ic = 2;
    int* pi = nullptr;
    int* const p2 = nullptr;
    const int* const p3 = nullptr;

    i = ic; // i is non-const
    // pi = p3; // pi and p3 types (const int != int)
    // pi = &ic; // pi and ic types (int != const int)
    // p3 = &ic; // p3 is const pointer, even with matching types
    // p2 = pi; // p2 is const pointer, even with matching types
    // ic = *p3; // ic is const, even with *p3
    
    return 0;
}