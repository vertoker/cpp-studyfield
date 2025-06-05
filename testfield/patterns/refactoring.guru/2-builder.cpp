// https://refactoring.guru/ru/design-patterns/builder/cpp/example#lang-features

#include <string>
#include <iostream>

class Product
{
    std::string name; // required
    int value1;
    double value2;
    bool value3;

public:
    Product(std::string name, int value1, double value2, bool value3)
        : name{std::move(name)}, value1{value1}, value2{value2}, value3{value3}
    { }
    ~Product() { }

    std::string getName() const noexcept { return name; }
    int getValue1() const noexcept { return value1; }
    double getValue2() const noexcept { return value2; }
    bool getValue3() const noexcept { return value3; }

    // important logic here

    class Builder
    {
        std::string name;
        int value1;
        double value2;
        bool value3;
        
    public:
        Builder(std::string name) : name{std::move(name)} { }

        Builder& setValue1(int value) { value1 = value; return *this; }
        Builder& setValue2(double value) { value2 = value; return *this; }
        Builder& setValue3(bool value) { value3 = value; return *this; }
        
        Product* build() const
        {
            Product* newProduct = new Product(std::move(name), value1, value2, value3);
            return newProduct;
        }
    };
};

int main()
{
    Product::Builder builder(std::move("what"));
    Product* product = builder.setValue1(1).setValue2(2.0).setValue3(true).build();
    std::cout << product->getName() << std::endl;
    std::cout << product->getValue1() << std::endl;
    std::cout << product->getValue2() << std::endl;
    std::cout << product->getValue3() << std::endl;
    delete product;
    return 0;
}