#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> v1; // 0
    std::vector<int> v2(10); // 10 of 0
    std::vector<int> v3(10, 42); // 10 of 42
    
    std::vector<int> v4 {10}; // 1
    std::vector<int> v5 {10, 42}; // 2

    std::vector<std::string> v6 {10}; // 1 (implicit conversion)
    std::vector<std::string> v7 {10, "hi"}; // 2 (implicit conversion)

    std::cout << v7.size() << std::endl;

    return 0;
}