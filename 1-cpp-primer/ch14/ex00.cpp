#include "stdint.h"

class Example
{
    int i;
public:
    Example() : Example(0) { }
    Example(int i) : i{i} { }

    // Operators
    Example operator+(const Example& other) { return Example(i + other.i); }
    Example operator-(const Example& other) { return Example(i - other.i); }
    Example operator*(const Example& other) { return Example(i * other.i); }
    Example operator/(const Example& other) { return Example(i / other.i); }
    
    Example operator%(const Example& other) { return Example(i % other.i); }
    Example operator^(const Example& other) { return Example(i ^ other.i); }
    
    Example operator&(const Example& other) { return Example(i & other.i); }
    Example operator|(const Example& other) { return Example(i | other.i); }
    Example operator&&(const Example& other) { return Example(i && other.i); }
    Example operator||(const Example& other) { return Example(i || other.i); }
    
    Example operator~() { return Example(~i); }
    Example operator!() { return Example(!i); }

    bool operator<(const Example& other) { return i < other.i; }
    bool operator<=(const Example& other) { return i <= other.i; }
    bool operator>(const Example& other) { return i > other.i; }
    bool operator>=(const Example& other) { return i >= other.i; }

    Example& operator++() { ++i; return *this; } // prefix
    Example operator++(int) { Example tmp = *this; ++(*this); return tmp; } // postfix
    Example& operator--() { --i; return *this; } // prefix
    Example operator--(int) { Example tmp = *this; --(*this); return tmp; } // postfix
    
    Example& operator+=(const Example& other) { i += other.i; return *this; }
    Example& operator-=(const Example& other) { i -= other.i; return *this; }
    Example& operator*=(const Example& other) { i *= other.i; return *this; }
    Example& operator/=(const Example& other) { i /= other.i; return *this; }
    
    Example& operator%=(const Example& other) { i %= other.i; return *this; }
    Example& operator^=(const Example& other) { i ^= other.i; return *this; }

    Example& operator&=(const Example& other) { i &= other.i; return *this; }
    Example& operator|=(const Example& other) { i |= other.i; return *this; }

    Example& operator<<=(const Example& other) { i <<= other.i; return *this; }
    Example& operator>>=(const Example& other) { i >>= other.i; return *this; }

    Example& operator[](const size_t& bit_index) { i >>= other.i; return *this; }
    Example& operator()(const size_t& bit_index) { i >>= other.i; return *this; }

    Example& operator->() { return *this; }
    Example& operator->*() { return *this; }

    void* operator new(size_t count) { return *this; }
    void* operator new[](size_t count) { return *this; }
    void operator delete(void* ptr) { return *this; }
    void operator delete[](void* ptr) { return *this; }

    bool operator<<(const Example& other) { return i << other.i; }
    bool operator>>(const Example& other) { return i >> other.i; }

    bool operator==(const Example& other) { return i == other.i; }
    bool operator!=(const Example& other) { return i != other.i; }

    Example& operator=(const Example& other) { return Example(!i); }

    Example operator,() { return Example(!i); }
};