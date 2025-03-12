#include <utility>

struct BigData
{
    void* data;

    void swap(BigData& other)
    {
        using std::swap;
        swap(data, other.data);
    }
};

namespace std
{
    template <>
    void swap(BigData& a, BigData& b)
    {
        a.swap(b);
    }
    
} // namespace std
