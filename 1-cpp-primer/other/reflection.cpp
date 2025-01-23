#include <iostream>

int main()
{
    std::cout << __func__ << std::endl;
    std::cout << __FILE__ << std::endl;
    std::cout << __LINE__ << std::endl;
    std::cout << __TIME__ << std::endl;
    std::cout << __DATE__ << std::endl;
    std::cout << std::endl;
    
    std::cout << __BYTE_ORDER__ << std::endl;
    std::cout << __COUNTER__ << std::endl;
    std::cout << __cpp_exceptions << std::endl;
    std::cout << __amd64__ << std::endl;
    std::cout << __ORDER_LITTLE_ENDIAN__ << std::endl;
    std::cout << __SIZEOF_DOUBLE__ << std::endl;
    std::cout << __TIMESTAMP__ << std::endl;
    std::cout << __WIN32__ << std::endl;
    std::cout << __WIN64__ << std::endl;
    std::cout << __x86_64__ << std::endl;

    return 0;
}