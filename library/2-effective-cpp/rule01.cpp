// 1. View C++ as a federation of languages

// Era 1: Clear C
#include <stdio.h>

const char* hi = "Hello";
void f()
{
    printf(hi);
}

// Era 2: C with classes

#include <memory>

class Cool
{
    Cool(size_t size) : ptr{malloc(size)} { }
    ~Cool() { free(ptr); }

    void* getPtr() { return ptr; }
private:
    void* ptr;
};

// Era 3: template metapocalypse

template <typename T>
class BaseAlloc
{
public:
    BaseAlloc(std::size_t size) : ptr(static_cast<T*>(std::malloc(ptr))) { }
    virtual ~BaseAlloc() { deallocate(); }

protected:
    void deallocate() { free(ptr); }

    T* ptr;
};

template <typename T, size_t Size>
class Alloc : public BaseAlloc<T>
{
public:
    Alloc() : BaseAlloc<T>(Size) { }
    ~Alloc() { this->deallocate(); }
};

// Era 4 : STL

#include <vector>
#include <algorithm>

template <typename T>
void remove_resize(std::vector<T>& vec, T toRemove)
{
    auto begin = vec.begin();
    auto newEnd = std::remove(begin, vec.end(), toRemove);
    auto newSize = newEnd - begin;
    vec.resize(newSize);
}

int main()
{
    return 0;
}