#include <iostream>
#include <string>

class Person
{
public:
    Person() = default;
    ~Person() = default;
    Person(const std::string& name, const std::string& address)
        : name(name), address(address) { }
    Person(std::string&& name, std::string&& address)
        : name(std::move(name)), address(std::move(address)) { }
    explicit Person(std::istream& is) { read(is, *this); } // should be explicit

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    void setName(const std::string& name) { this->name = name; }
    void setAddress(const std::string& address) { this->address = address; }
    void setName(std::string&& name) noexcept { this->name = std::move(name); }
    void setAddress(std::string&& address) noexcept { this->address = std::move(address); }

private:
    std::string name;
    std::string address;
};

std::istream& read(std::istream& is, Person& person)
{
    std::string name, address;
    is >> name >> address;
    person.setName(std::move(name));
    person.setAddress(std::move(address));
    return is;
}
