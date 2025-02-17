#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    std::string str;
    for (int i = 0; i < argc; ++i)
        str += std::string(argv[i]) + ' ';
    std::cout << str << std::endl;

    char* begin = *argv;
    const char* end = *argv + argc;
    while (begin != end)
        std::cout << begin++ << ' ';
    std::cout << std::endl;

    return 0;
}