#include <string>
#include <iostream>

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);

    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp)
        : ps(new std::string(*hp.ps)), i(hp.i) { }
    ~HasPtr()
        { delete ps; }

    HasPtr& operator=(const HasPtr& hp)
    {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    
    void show() { std::cout << *ps << std::endl; }
    
private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::swap(lhs.ps, rhs.ps);
    std::swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}