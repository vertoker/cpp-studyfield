#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    // ex09
    std::map<std::string, std::list<std::size_t>> m;

    // ex10
    std::map<std::vector<int>::iterator, int> mv; // < on iterator is defined
    std::map<std::vector<int>::iterator, int> ml; // < in iterator is not defined

    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0)); // ok

    std::list<int> li;
    //ml.insert(std::pair<std::vector<int>::iterator, int>(li.begin(), 0)); // error, no <

    return 0;
}