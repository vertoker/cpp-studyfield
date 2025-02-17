#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::unique_ptr<std::string> p1(new std::string("pezy")); // legal
    // unique_ptr<string> p2(p1); // illegal, unique_ptr doesn't have copy ctor
    // unique_ptr<string> p3 = p1; // illegal, unique_ptr doesn't have copy assign
    
    std::cout << *p1 << std::endl;
    p1.reset(nullptr);

    return 0;
}