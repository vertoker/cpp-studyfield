#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

int main()
{
    std::ifstream ifs("../data/example.txt");
    
    std::istream_iterator<std::string> in(ifs), eof;
    std::ostream_iterator<std::string> out(std::cout, "\n");

    std::vector<std::string> vec;
    std::copy(in, eof, std::back_inserter(vec));

    std::copy(vec.begin(), vec.end(), out);
    return 0;
}