#include <map>
#include <string>
#include <iostream>

int main()
{
    std::multimap<std::string, std::string> authors{
        { "alan", "DMA" },
        { "pezy", "LeetCode" },
        { "alan", "CLRS" },
        { "wang", "FTP" },
        { "pezy", "CP5" },
        { "wang", "CPP-Concurrency" }
    };
    // want to delete an element that author is [Alan], work is [112].
    // vertoker: I'm too lazy to try prevent my copying of that exercise
    std::string author = "pezy";
    std::string work = "CP5";
    
    auto found = authors.find(author);
    auto count = authors.count(author);
    while (count) {
        if (found->second == work) {
            authors.erase(found);
            break;   
        }
        ++found;
        --count;
    }
    
    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}