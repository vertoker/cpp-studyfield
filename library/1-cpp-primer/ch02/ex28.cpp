#include <iostream>

int main()
{
    int i; // variable without initializer
    // int* const cp; // const pointer to non-const type, const requires initializer

    int* p1; // pointer without initializer
    // int* const p2; // same as cp, const requires initializer

    // const int ic; // const requires initalizer
    // const int& r; // if ic was valid, then it works, therefore reference still can't be empty

    // const int* const p3; // const pointer to const type, const in pointer requires initializer

    const int* p; // non-const pointer to const type, doesn't need initializer (still better initialize with nullptr)
    
    return 0;
}