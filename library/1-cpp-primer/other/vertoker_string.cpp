#include "vertoker_string.h"

#include <string>

vertoker::String::String(const char *str, size_t length) : ptr{new char[length + 1]}
{
    memcpy(ptr, str, length);
    ptr[length] = '\0';
}
vertoker::String::String(const char* str = "") : String(str, strlen(str)) {}
vertoker::String::~String()
{
    delete[] ptr;
}

vertoker::String::String(const String& other) : ptr{other.ptr} {}

vertoker::String& vertoker::String::operator=(const String& other)
{
    if (this != &other)
    {
        String temp(other.ptr);
        
        auto temp2 = ptr;
        ptr = temp.ptr;
        temp.ptr = temp2;
    }
    return *this;
}

// TODO finish with move semantics
vertoker::String::String(const String&& other) : ptr{other.ptr} {}

vertoker::String& vertoker::String::operator=(const String&& other)
{
    return *this;
}