#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::istream_iterator<int> in(std::cin), eof;
    std::ostream_iterator<int> out(std::cout, " ");
    std::vector<int> vec;

    while (in != eof)
        vec.push_back(*in++);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), out);
    
    return 0;
}