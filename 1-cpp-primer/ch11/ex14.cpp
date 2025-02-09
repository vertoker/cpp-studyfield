#include <iostream>
#include <map>
#include <string>
#include <vector>

class Families
{
public:
    using Child = std::pair<std::string, std::string>;
    using Children = std::vector<Child>;
    using Data = std::map<std::string, Children>;

    void add(const std::string& lastName, const std::string& firstName, const std::string& birthday)
    {
        data[lastName].emplace_back(firstName, birthday);
    }

    void print() const
    {
        for (const auto& pair : data)
        {
            std::cout << pair.first << ":" << std::endl;
            for (const auto& child : pair.second)
                std::cout << child.first << " " << child.second << std::endl;
            std::cout << std::endl;
        }
    }
private:
    Data data;
};

int main()
{
    Families families;
    auto msg = "Enter last name, first name and birthday: \n";
    for (std::string ln, fn, br; 
        std::cout << msg, std::cin >> ln >> fn >> br; 
        families.add(ln, fn, br));
    families.print();
    
    return 0;
}