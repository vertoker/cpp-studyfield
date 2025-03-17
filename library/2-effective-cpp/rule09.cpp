// 9. Never call virtual functions during construction or destruction

class Base
{
public:
    Base() { }
    virtual ~Base() { }
};

class Derived : public Base
{
    
}