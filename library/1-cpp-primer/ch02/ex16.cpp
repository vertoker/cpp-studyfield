#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0.0, &r2 = d;

    // r2 = 3.14159; // 3.14159 is not a rvalue
    r2 = r1; // reference can copy source lvalue from another reference, now r2 => i => 0;
    i = r2; // usual copy value from... yourself?
    r1 = d; // now r1 => d => 0.0
    
    return 0;
}