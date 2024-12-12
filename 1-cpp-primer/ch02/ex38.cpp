#include <iostream>

int main()
{
    // `decltype` and `auto` very simular, but still not the same
    
    // first of all, they "source" of object type is different
    // `auto` takes it from initializer
    auto i = 0; // int
    // `decltype` takes it from type of another object
    decltype(i) i2; // int without initalizer

    // second, `decltype` and `auto` represents not the same types of types
    // `auto` represents only base type, without modifiers and specifiers (not everytime)
    auto* pi = &i; // int*
    // `decltype` represents full compound type, includes modifiers and specifiers
    decltype(pi) pi2; // int*

    return 0;
}