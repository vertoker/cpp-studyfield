// Based on https://en.cppreference.com/w/cpp/language/rule_of_three

#ifndef VERTOKER_STRING_H
#define VERTOKER_STRING_H

#include "stdint.h"
#include "string.h"

#include <iostream>

namespace vertoker
{
    class String
    {
    public:
        String(const char* str, size_t length); // constructor
        explicit String(const char* str = ""); // constructor
        ~String(); // 1. destructor

        String(const String& other); // 2. copy constructor
        String& operator=(const String& other); // 3. copy assignment

        String(const String&& other); // 4. move constructor
        String& operator=(const String&& other); // 5. move assignment

        const char* c_str() const { return ptr; } // accessor

    private:
        char* ptr;
    };
}

#endif // VERTOKER_STRING_H