#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class ShorterString {
public:
    bool operator()(std::string const& s1, std::string const& s2) const { return s1.size() < s2.size(); }
};

class BiggerEqual {
    size_t sz_;
public:
    BiggerEqual(size_t sz) : sz_(sz) { }
    bool operator()(std::string const& s) { return s.size() >= sz_; }
};

class Print {
public:
    void operator()(std::string const& s) { std::cout << s << " "; }
};

std::string make_plural(size_t ctr, std::string const& word, std::string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

void elimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz ) {
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), BiggerEqual(sz));
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    for_each(wc, words.end(), Print());
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(vec, 4);
    return 0;
}