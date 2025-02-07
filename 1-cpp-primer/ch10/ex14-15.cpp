#include <iostream>

int main()
{
    [](){}; // empty lambda
    [](){}(); // call empty lambda

    auto a { [](){} }; // lambda variable
    auto a2 = [](){}; // lambda variable 2
    a(); // call lambda variable

    [](int a, int b) -> double { return a + b; }; // return specified type
    

    // ex14
    auto sum { [](const int a, const int b) { return a + b; } };
    std::cout << sum(2, 2) << std::endl;

    // ex15
    int i = 42;
    auto add = [i](int a) { return i + a; };
    std::cout << add(58) << std::endl;

    return 0;
}