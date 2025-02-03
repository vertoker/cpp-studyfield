#include <vector>
#include <list>

int main()
{
    std::list<int> l1;
    std::vector<double> v1(l1.begin(), l1.end());
    
    std::vector<int> v2;
    std::vector<double> v3(v2.begin(), v2.end());
    
    return 0;
}