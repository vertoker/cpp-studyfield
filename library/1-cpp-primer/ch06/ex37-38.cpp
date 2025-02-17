#include <iostream>

// decl 1
using ArrT = std::string[10];
ArrT& func1(ArrT& arr);

// decl 2
auto func2(ArrT& arr) -> std::string(&)[10];

// decl 3
std::string arrS[10];
decltype(arrS)& func3(ArrT& arr);

ArrT &func1(ArrT &arr)
{
    return arr;
}
auto func2(ArrT &arr) -> std::string (&)[10]
{
    return arr;
}
decltype(arrS) &func3(ArrT &arr)
{
    return arr;
}
