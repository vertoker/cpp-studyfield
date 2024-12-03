#include <iostream>

int main()
{
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */; // you can't compile it
    std::cout << /* "*/" /* "/*" */; // wow
}