#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs("../data/example.txt", std::ifstream::in);
    std::vector<std::string> vec;

    std::string wordBuf;
    if (ifs)
    {
        while (ifs >> wordBuf)
            vec.push_back(wordBuf);
        wordBuf.clear();
    }
    
    for (const auto& str : vec)
        std::cout << str << std::endl;
    
    return 0;
}