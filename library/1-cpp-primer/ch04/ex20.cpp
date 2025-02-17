#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::vector<int>::iterator iter = vec.begin();

    *iter++; // equals to *(iter++), increase iterator
    (*iter)++; // postfix number increment
    // *iter.empty(); // incorrect, right will be (*iter).empty()
    // iter->empty(); // incorrect, iter is not a pointer
    ++*iter; // equals to ++(*iter), prefix number increment
    // iter++->empty(); // incorrect, iter not a pointer
    
    return 0;
}