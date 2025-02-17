#pragma once

#include <functional>
#include <cstddef>

#include "Deleter.hpp"

namespace ex28
{
    template <typename T>
    class SharedPointer;

    template <typename T>
    void swap(SharedPointer<T>& a, SharedPointer<T>& b);

    template <typename T>
    class SharedPointer
    {
        friend void swap<T>(SharedPointer<T>& a, SharedPointer<T>& b);

    public:
        SharedPointer() : ptr{nullptr}, counter{new size_t(1)}, deleter{Deleter{}} { }
        explicit SharedPointer(T* rawPtr)
            : ptr{rawPtr}, counter{new size_t(1)}, deleter{Deleter{}} { }
        ~SharedPointer() { SelfDestroy(); }

        SharedPointer(const SharedPointer& other); // copy ctor
        SharedPointer(SharedPointer&& other) noexcept; // move ctor
        SharedPointer& operator=(const SharedPointer& other); // copy assign
        SharedPointer& operator=(SharedPointer&& other) noexcept; // move assign
        
        operator bool() const { return ptr ? true : false; }
        T& operator*() const { return *ptr; }
        T* operator->() const { return ptr; }

        inline size_t use_count() const { return *counter; }
        inline T* get() const noexcept { return ptr; }
        inline bool unique() const { return 1 == *counter; }
        inline void swap(SharedPointer& other) const { ex28::swap(*this, other); }

        inline void reset() { SelfDestroy(); }
        void reset(T* newPtr);
        void reset(T* newPtr, const std::function<void(T*)>& d);

    private:
        T* ptr;
        size_t* counter;
        std::function<void(T*)> deleter;

        void SelfDestroy()
        {
            if (ptr && 0 == --*counter)
            {
                delete counter;
                deleter(ptr);
            }
            else if (!ptr)
                delete counter;
            
            counter = nullptr;
            ptr = nullptr;
        }
    };

    template <typename T>
    SharedPointer<T>::SharedPointer(const SharedPointer& other)
        : ptr{other.ptr}, counter{other.counter}, deleter{other.deleter}
    {
        ++*counter;
    }
    
    template <typename T>
    SharedPointer<T>::SharedPointer(SharedPointer&& other) noexcept
        : ptr{other.ptr}, counter{other.counter}, deleter{std::move(other.deleter)}
    {
        other.ptr = nullptr;
        other.counter = nullptr;
    }
    
    template <typename T>
    SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other)
    {
        ++*counter;
        SelfDestroy();
        ptr = other.ptr;
        counter = other.counter;
        deleter = other.deleter;
        return *this;
    }
    
    template <typename T>
    SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer&& other) noexcept
    {
        swap(other);
        other.SelfDestroy();
        return *this;
    }

    template <typename T>
    void swap(SharedPointer<T>& a, SharedPointer<T>& b)
    {
        std::swap(a.ptr, b.ptr);
        std::swap(a.counter, b.counter);
        std::swap(a.deleter, b.deleter);
    }
    
    template <typename T>
    void SharedPointer<T>::reset(T* newPtr)
    {
        if (ptr == newPtr) return;
        SelfDestroy();
        ptr = newPtr;
        counter = new size_t(1);
    }
    
    template <typename T>
    void SharedPointer<T>::reset(T* newPtr, const std::function<void(T*)>& d)
    {
        reset(newPtr);
        deleter = d;
    }
} // namespace vertoker
