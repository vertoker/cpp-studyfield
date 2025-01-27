#include <iostream>
#include <vector>
#include <string>

class BigData
{
public:
    BigData() { std::cout << "Create BigData" << std::endl; }
    // Do not touch copy constructor, use move
    BigData(const BigData& other) { std::cout << "Copy BigData" << std::endl; } // lvalue
    BigData(BigData&& other) { std::cout << "Move BigData" << std::endl; } // rvalue
};

class ClassA
{
    BigData* data;
public:
    ClassA() : data(new BigData()) { };
    ClassA(const ClassA& other) { data = new BigData(*other.data); }
    ClassA(ClassA&& other) : data(other.data) { other.data = nullptr; }
    ~ClassA() { delete data; }

    ClassA& operator=(const ClassA& other)
    {
        if (this == &other) return *this;
        delete data;
        data = new BigData(*other.data);
        return *this;
    }
    ClassA& operator=(ClassA&& other)
    {
        if (this == &other) return *this;
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }
};

struct Str {};

class A
{
    std::string data;
    Str* str;

public:
    A(Str* other) : str(other) { }
    A(const A& other) : data(data) { }
    A(A&& other) noexcept : data(static_cast<std::string&&>(data)) { }
    
    A& operator=(const A& other)
    {
        if (this == &other) return *this;
        data = other.data;
        return *this;
    }
    A& operator=(A&& other) noexcept
    {
        if (this == &other) return *this;
        data = static_cast<std::string&&>(data);
        return *this;
    }
};

class ClassB
{
    ClassA classA;
public:
    ClassB(const ClassA& classA) : classA(classA) { std::cout << "Copy ClassB" << std::endl; };

    ClassB(ClassA&& classA) : classA(std::move(classA))
    {
        std::cout << "Move ClassB" << std::endl;
    }
};

int main()
{
    std::cout << "1" << std::endl;
    std::vector<ClassA> vec1;
    vec1.push_back(ClassA{});

    std::cout << "2" << std::endl;
    ClassB b2(ClassA{});

    std::cout << "3" << std::endl;
    ClassA a3;
    ClassB b3(a3);

    std::cout << "4" << std::endl;
    ClassA a4;
    ClassB b4(std::move(a4));

    std::cout << "5" << std::endl;
    ClassA a5;
    ClassB b5(static_cast<ClassA&&>(a5));
    
    std::cout << "6" << std::endl;
    std::vector<ClassA> vec1;
    vec1.push_back(static_cast<ClassA&&>(ClassA{}));

    return 0;
}