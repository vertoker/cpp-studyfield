#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

struct IsInRange
{
    IsInRange(std::size_t lower, std::size_t upper)
        :_lower(lower), _upper(upper)
    { }

    bool operator()(std::string const& str) const
    {
        return str.size() >= _lower && str.size() <= _upper;
    }

    std::size_t lower_limit() const
    {
        return _lower;
    }

    std::size_t upper_limit() const
    {
        return _upper;
    }
private:
    std::size_t _lower;
    std::size_t _upper;
};

int main()
{
    std::size_t lower = 1;
    auto uppers = { 3u, 4u, 5u, 6u, 7u, 8u, 9u, 10u, 11u, 12u, 13u, 14u };
    std::vector<IsInRange> predicates;
    for (auto upper : uppers)
        predicates.push_back(IsInRange{ lower, upper });
    
    std::map<std::size_t, std::size_t> count_table;
    for (auto upper : uppers)
        count_table[upper] = 0;
    
    std::ifstream fin("../data/storyDataFile.txt");
    for (std::string word; fin >> word; /* */)
        for (auto is_size_in_range : predicates)
            if (is_size_in_range(word))
                ++count_table[is_size_in_range.upper_limit()];
    
    for (auto pair : count_table)
        std::cout << "count in range [1, " << pair.first << "] : " << pair.second << std::endl;

    return 0;
}