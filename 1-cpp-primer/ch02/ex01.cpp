#include <iostream>

int main()
{
    // logic types
    std::cout << "bool: " << sizeof(bool) << " bytes, " << sizeof(bool) * 8 << " bits" << std::endl;

    // "string" integer types
    std::cout << "char: " << sizeof(char) << " bytes, " << sizeof(char) * 8 << " bits" << std::endl; // also byte
    std::cout << "wchar_t: " << sizeof(wchar_t) << " bytes, " << sizeof(wchar_t) * 8 << " bits" << std::endl;
    std::cout << "char16_t: " << sizeof(char16_t) << " bytes, " << sizeof(char16_t) * 8 << " bits" << std::endl;
    std::cout << "char32_t: " << sizeof(char32_t) << " bytes, " << sizeof(char32_t) * 8 << " bits" << std::endl;

    // integer types
    std::cout << "short: " << sizeof(short) << " bytes, " << sizeof(short) * 8 << " bits" << std::endl;
    std::cout << "unsigned: " << sizeof(unsigned) << " bytes, " << sizeof(unsigned) * 8 << " bits" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes, " << sizeof(int) * 8 << " bits" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes, " << sizeof(long) * 8 << " bits" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes, " << sizeof(long long) * 8 << " bits" << std::endl;
    
    // floating point number types
    std::cout << "float: " << sizeof(float) << " bytes, " << sizeof(float) * 8 << " bits" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes, " << sizeof(double) * 8 << " bits" << std::endl;
    std::cout << "long double: " << sizeof(long double) << " bytes, " << sizeof(long double) * 8 << " bits" << std::endl;

    // `void` means nothing, then it has no size (in computer meaning)
    return 0;
}