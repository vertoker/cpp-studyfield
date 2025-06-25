#include <iostream>

struct AField
{
    AField() { std::cout << "AField" << std::endl; }
    AField(const char* name) { std::cout << name << std::endl; }
    ~AField() { std::cout << "~AField" << std::endl; }
};
struct BField
{
    BField() { std::cout << "BField" << std::endl; }
    ~BField() { std::cout << "~BField" << std::endl; }
};
struct CField
{
    CField() { std::cout << "CField" << std::endl; }
    ~CField() { std::cout << "~CField" << std::endl; }
};
struct DField
{
    DField() { std::cout << "DField" << std::endl; }
    ~DField() { std::cout << "~DField" << std::endl; }
};

struct ABase
{
    ABase() { std::cout << "ABase" << std::endl; }
    ABase(const char* name) : a{name} { std::cout << "ABase" << std::endl; }
    //ABase(const char* name) { a = AField(name); std::cout << "ABase" << std::endl; }
    ~ABase() { std::cout << "~ABase" << std::endl; }

    AField a;
};
struct BBase
{
    BBase() { std::cout << "BBase" << std::endl; }
    ~BBase() { std::cout << "~BBase" << std::endl; }

    BField b;
};

struct Current : ABase, BBase
{
    Current() { std::cout << "Current" << std::endl; }
    Current(const char* name) : ABase(name) { std::cout << "Current" << std::endl; }
    ~Current() { std::cout << "~Current" << std::endl; }

    CField c;
    DField d;
};

int main()
{
    //Current current;
    Current current2("AField override");
    std::cout << sizeof(current2) << std::endl;
    return 0;
}

// Class init: fields => ctor
// Class dstr: dtor => fields
// - Starts with base classes full init
// - Memory Layout: AField, BField, CField,