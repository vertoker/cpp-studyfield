#include <iostream>
#include <string>

std::string global_str;
long long global_num;

int main()
{
    long long local_num;
    std::string local_str;

    // initialized
    std::cout << global_str << std::endl;
    std::cout << global_num << std::endl;
    // uninitialized
    std::cout << local_num << std::endl;
    std::cout << local_str << std::endl;

    char* p1;
    char* p2;
    char* p3;
    std::cout << &p1 << std::endl;
    std::cout << &p2 << std::endl;
    std::cout << &p3 << std::endl;
    return 0;
}