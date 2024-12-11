#include <iostream>

int main()
{
    const int v2 = 0; // low-level const
    int v1 = v2; // non-const
    int* p1 = &v1; // non-const
    int& r1 = v1; // non-const
    const int* p2 = &v2; // low-level const
    const int* const p3 = &v2; // low-level const and high-level const
    const int& r2 = v2; // low-level const
    int* const p4 = &v1; // high-level const

    r1 = v2; // reference can be to the const type
    // p1 = p2; // can't convert types from const to non-const
    p2 = p1; // easy can convert types from non-const to const
    // p1 = p3; // can't convert types from const to non-const
    p2 = p3; // types matching and high-level const of p3 easy copt to non-const p2
    
    return 0;
}