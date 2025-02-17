#include <vector>
#include <iostream>

inline int add(const int a, const int b) { return a + b; }
inline int substract(const int a, const int b) { return a - b; }
inline int multiply(const int a, const int b) { return a * b; }
inline int divide(const int a, const int b) { return a / b; }

typedef int FuncType1(const int, const int);
typedef decltype(add) FuncType2;

typedef int (*FuncTypeP1)(const int, const int);
typedef decltype(add) *FuncTypeP2;

int main()
{
    std::vector<int (*)(const int, const int)> arr1 { add };
    std::vector<decltype(add)*> arr2 { add };
    std::vector<FuncType1*> arr3 { add };
    std::vector<FuncType2*> arr4 { add };
    std::vector<FuncTypeP1> arr5 { add };
    std::vector<FuncTypeP2> arr6 { add };

    std::vector<FuncType1*> arr { add, substract, multiply, divide };
    for (auto f : arr)
        std::cout << f(2, 2) << std::endl;
    
    std::vector<FuncType2*> arr2(4, nullptr);
    for (auto& f : arr2)
        f = add;
    
    return 0;
}