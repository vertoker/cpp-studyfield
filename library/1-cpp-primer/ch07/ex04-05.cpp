#include <iostream>
#include <string>

class Person
{
    std::string name;
    std::string address;

public:
    Person(const std::string& name, const std::string& address) : name(name), address(address) { }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
};

int main()
{
    Person person("1", "2");
    std::cout << person.getName() << std::endl;
    std::cout << person.getAddress() << std::endl;
    
    return 0;
}