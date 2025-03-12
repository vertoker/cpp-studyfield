#include <iostream>

// 1. Pure virtual (abstract)

struct B1 {
    virtual void print(const std::string& str) = 0; // pure virtual
};
struct D1 : public B1 {
    void print(const std::string& str) override {
        std::cout << str << std::endl;
    }
};

// 2. Virtual

struct B2 {
    virtual void print1(const std::string& str) { } // virtual
    virtual void print2(const std::string& str) { } // virtual
};
struct D2 : public B2 {
    void print2(const std::string& str) override {
        std::cout << str << std::endl;
    }
};

// 3. Non-virtual

struct B3 {
    void print(const std::string& str) { // non-virtual
        std::cout << "B3: " << str << std::endl;
    }
};
struct D3 : public B3 {
    void print(const std::string& str) {
        std::cout << "D3: " << str << std::endl;
    }
};

int main()
{
    D1 d1;
    d1.print("D1");

    D2 d2;
    d2.print1("D2-1");
    d2.print2("D2-2");

    D3 d3;
    d3.print("D3");
    d3.B3::print("D3");

    return 0;
}