#include <map>
#include <string>
#include <fstream> 
#include <iostream>
#include <sstream>

std::map<std::string, std::string> buildMap(std::ifstream& map_file)
{
    std::map<std::string, std::string> map;
    for (std::string key, value; map_file >> key && getline(map_file, value); )
        if (value.size() > 1) map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
    return map;
}

const std::string& transform(const std::string& s, const std::map<std::string, std::string>& m)
{
    auto map_it = m.find(s);
    return map_it == m.cend() ? s : map_it->second;
}

void word_transform(std::ifstream& map, std::ifstream& input)
{
    auto trans_map = buildMap(map);
    for (std::string text; getline(input, text); )
    {
        std::istringstream iss(text);
        for (std::string word; iss >> word; )
            std::cout << transform(word, trans_map) << " ";
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream ifs_map("../data/transformation_map.txt"), ifs_content("../data/bad_message.txt");
    if (ifs_map && ifs_content) word_transform(ifs_map, ifs_content);
    else std::cerr << "can't find data" << std::endl;
}