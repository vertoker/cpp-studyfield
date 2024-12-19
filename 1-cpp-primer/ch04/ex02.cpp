#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;

    auto a = * ( vec.begin() );
    auto b = ( * ( vec.begin() ) ) + 1;
    
    return 0;
}