//

#include <iostream>

class Animal
{
public:
    virtual void makeSound() const = 0; // abstract
    virtual ~Animal() = default;
};

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "meow\n";
    }
};
class Dog : public Animal
{
public:
    void makeSound() const override
    {
        std::cout << "woof\n";
    }
};

enum class AnimalType
{
    Cat = 0,
    Dog = 1,
};

// factory method
Animal* makeAnimal(AnimalType t)
{
    if (t == AnimalType::Cat)
        return new Cat();
    if (t == AnimalType::Dog)
        return new Dog();
    return nullptr;
}

int main()
{
    auto animal = makeAnimal(AnimalType::Dog);
    animal->makeSound();
    delete animal;
    return 0;
}