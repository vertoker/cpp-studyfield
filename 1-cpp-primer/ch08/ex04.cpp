#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs("../data/example.txt");
    std::vector<std::string> vec;

    std::string lineBuf;
    if (ifs)
    {
        while (std::getline(ifs, lineBuf))
            vec.push_back(lineBuf);
        lineBuf.clear();
    }

    for (const auto& str : vec)
        std::cout << str << std::endl;
    
    return 0;
}