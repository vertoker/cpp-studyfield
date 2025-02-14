#include "stdint.h"
#include <cstdio>
#include <cstdlib>
#include <new>

// https://en.cppreference.com/w/cpp/language/operators
class Operators
{
    int i;
public:
    Operators() : Operators(0) { }
    Operators(int i) : i{i} { }

    Operators(const Operators& other)
    {
        i = other.i;
    }
    Operators(Operators&& other)
    {
        i = other.i;
        other.i = 0;
    }

    // Operators
    Operators operator+(const Operators& other) { return Operators(i + other.i); }
    Operators operator-(const Operators& other) { return Operators(i - other.i); }
    Operators operator*(const Operators& other) { return Operators(i * other.i); }
    Operators operator/(const Operators& other) { return Operators(i / other.i); }
    
    Operators operator%(const Operators& other) { return Operators(i % other.i); }
    Operators operator^(const Operators& other) { return Operators(i ^ other.i); }
    
    Operators operator&(const Operators& other) { return Operators(i & other.i); }
    Operators operator|(const Operators& other) { return Operators(i | other.i); }
    Operators operator&&(const Operators& other) { return Operators(i && other.i); }
    Operators operator||(const Operators& other) { return Operators(i || other.i); }
    
    Operators operator~() { return Operators(~i); }
    Operators operator!() { return Operators(!i); }

    bool operator<(const Operators& other) { return i < other.i; }
    bool operator<=(const Operators& other) { return i <= other.i; }
    bool operator>(const Operators& other) { return i > other.i; }
    bool operator>=(const Operators& other) { return i >= other.i; }

    bool operator<<(const Operators& other) { return i << other.i; }
    bool operator>>(const Operators& other) { return i >> other.i; }
    bool operator==(const Operators& other) { return i == other.i; }
    bool operator!=(const Operators& other) { return i != other.i; }

    Operators& operator++()
    {
        ++i;
        return *this;
    }
    Operators operator++(int)
    {
        Operators tmp = *this;
        operator++();
        return tmp;
    }
    Operators& operator--()
    {
        --i;
        return *this;
    }
    Operators operator--(int)
    {
        Operators tmp = operator*();
        operator--();
        return tmp;
    }
    
    Operators& operator+=(const Operators& other) { i += other.i; return *this; }
    Operators& operator-=(const Operators& other) { i -= other.i; return *this; }
    Operators& operator*=(const Operators& other) { i *= other.i; return *this; }
    Operators& operator/=(const Operators& other) { i /= other.i; return *this; }
    
    Operators& operator%=(const Operators& other) { i %= other.i; return *this; }
    Operators& operator^=(const Operators& other) { i ^= other.i; return *this; }

    Operators& operator&=(const Operators& other) { i &= other.i; return *this; }
    Operators& operator|=(const Operators& other) { i |= other.i; return *this; }

    Operators& operator<<=(const Operators& other) { i <<= other.i; return *this; }
    Operators& operator>>=(const Operators& other) { i >>= other.i; return *this; }

    Operators& operator[](const size_t& bit_index) { return *this; }
    Operators& operator()(const size_t& bit_index) { return *this; }

    // https://en.cppreference.com/w/cpp/language/operator_member_access 
    Operators& operator*() { return *this; }
    Operators* operator&() { return this; }
    Operators& operator->() { return *this; }

    // https://en.cppreference.com/w/cpp/memory/new/operator_new
    void* operator new(size_t size)
    {
        if (size == 0) ++size;

        void* ptr = std::malloc(size);
        if (ptr) return ptr;
        
        throw std::bad_alloc{};
    }
    void* operator new[](size_t size)
    {
        if (size == 0) ++size;

        void* ptr = std::malloc(size);
        if (ptr) return ptr;
        
        throw std::bad_alloc{};
    }
    void operator delete(void* ptr) { std::free(ptr); }
    void operator delete[](void* ptr) { std::free(ptr); }

    Operators& operator=(const Operators& other)
    {
        if (this == &other) return *this;
        i = other.i;
        return *this;
    }
    Operators& operator=(Operators&& other) noexcept
    {
        if (this == &other) return *this;
        i = other.i;
        other.i = 0;
        return *this;
    }
    Operators& operator=(Operators other) noexcept
    {
        if (this == &other) return *this;
        i = other.i;
        other.i = 0;
        return *this;
    }

    int operator,(int& b) { return i; }
};