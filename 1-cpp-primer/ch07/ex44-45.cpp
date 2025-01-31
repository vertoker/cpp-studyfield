#include <vector>

class NoDefault
{
    int i;
public:
    NoDefault(int i) : i(i) { }
};

class C
{
    NoDefault noDefault;
public:
    C() : noDefault(0) { }
};

int main()
{
    std::vector<int> vec1(10); // build in type
    std::vector<C> vec2(10); // has default ctor
    // std::vector<NoDefault> vec3(10); // no have default ctor

    return 0;
}