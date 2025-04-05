#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include <unordered_map>

std::string ConstructCode(const std::string& word, const std::string* codes)
{
    std::stringstream ss;
    for (auto letter : word)
        ss << codes[letter - 'A'];
    return ss.str();
}

int main()
{
    const std::string codes[26] {
        "2", "22", "222",         // ABC
        "3", "33", "333",         // DEF
        "4", "44", "444",         // GHI
        "5", "55", "555",         // JKL
        "6", "66", "666",         // MNO
        "7", "77", "777", "7777", // PQRS
        "8", "88", "888",         // TUV
        "9", "99", "999", "9999"  // WXYZ
    };

	std::string s;
    s.reserve(128000);
    std::cin >> s;

    std::unordered_map<std::string, std::string> dict;
    
    uint16_t n;
    std::cin >> n;
    dict.reserve(n);

    for (size_t i = 0; i < n; ++i)
    {
        std::string word;
        word.reserve(256);
        std::cin >> word;

        std::string code = ConstructCode(word, codes);
        dict.insert(std::make_pair(std::move(code), std::move(word)));
    }
    
    size_t counter = 0;
    std::string buffer;
    buffer.reserve(256 * 4);
    bool firstPrint = true;

    while (counter != s.size())
    {
        while (!dict.contains(buffer))
            buffer += s[counter++];
        
        if (firstPrint)
            firstPrint = false;
        else std::cout << ' ';
    
        std::cout << dict[buffer];
        buffer.clear();
    }
    
	return 0;
}