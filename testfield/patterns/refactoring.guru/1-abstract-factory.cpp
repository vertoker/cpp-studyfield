// https://refactoring.guru/ru/design-patterns/abstract-factory/cpp/example#lang-features

class AbstractProductA
{
public:
    virtual ~AbstractProductA() { }
};
class AbstractProductB
{
public:
    virtual ~AbstractProductB() { }
};

class ProductA1 : public AbstractProductA { };
class ProductA2 : public AbstractProductA { };
class ProductB1 : public AbstractProductB { };
class ProductB2 : public AbstractProductB { };

class AbstractFactory
{
public:
    virtual ~AbstractFactory() { }
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};
class Factory1 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override { return new ProductA1(); }
    AbstractProductB* createProductB() override { return new ProductB1(); }
};
class Factory2 : public AbstractFactory
{
public:
    AbstractProductA* createProductA() override { return new ProductA2(); }
    AbstractProductB* createProductB() override { return new ProductB2(); }
};

int main()
{
    Factory1 f1;
    auto productA1 = f1.createProductA();
    delete productA1;
    Factory2 f2;
    auto productB2 = f2.createProductB();
    delete productB2;
}