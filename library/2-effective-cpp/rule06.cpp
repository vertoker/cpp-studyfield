// 6. Explicitly disallow the use of compiler-generated functions you do not want

#include <iostream>

class Data1
{
public:
    Data1() : data{malloc(1024)} { }
    ~Data1() { free(data); }

    // variant 1: delete like this
    Data1(const Data1& rhs) = delete;
    Data1& operator=(const Data1& rhs) = delete;

private:
    void* data;
};

class Uncopyable
{
protected:
    Uncopyable() { }
    ~Uncopyable() { }
private:
    Uncopyable(const Uncopyable& rhs) { }
    Uncopyable& operator=(const Uncopyable& rhs) { }
};

class Data2 : private Uncopyable
{
public:
    Data2() : data{malloc(1024)} { }
    ~Data2() { free(data); }
private:
    void* data;
};
