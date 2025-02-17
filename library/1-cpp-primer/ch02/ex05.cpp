#include <string>

int main()
{
    char a1 = 'a';
    wchar_t a2 = L'a';
    std::string a3 = "a";
    std::wstring a4 = L"a";

    int b1 = 10;
    unsigned int b2 = 10u;
    long b3 = 10l;
    unsigned long b4 = 10ul;
    int b5 = 012; // base 8
    int b6 = 0xC; // base 16

    double c1 = 3.14;
    float c2 = 3.14f;
    long double c3 = 3.14l;

    int d1 = 10;
    unsigned int d2 = 10u;
    double d3 = 10.;
    double d4 = 10e-2;

    return 0;
}