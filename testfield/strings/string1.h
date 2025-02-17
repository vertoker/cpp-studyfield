#include "string"
#include <iostream>

namespace vertoker
{
    class string
    {
    public:
        string(const char* str, std::size_t length);
        string(const char* str);

        string();
        ~string();

        // copy
        string(const string& other);
        string& operator=(const string& other);
        string& operator=(const char* other);

        // move
        string(string&& other);
        string& operator=(string&& other);

        // other
        string& operator+=(const string& other);

        // functions
        inline const char* c_str() const { return cstr; }
        inline char* data() const { return cstr; }
        inline size_t length() const noexcept { return strlen(cstr); }

        inline char& front() const noexcept { return cstr[0]; }
        inline char& back() const noexcept { return cstr[strlen(cstr)]; };
        inline char& at(const size_t index) const noexcept { return cstr[index]; };

    private:
        char* cstr;
    }; // string

    // external
    string& operator+(const string& str1, const string& str2);
    std::ostream& operator<<(std::ostream& os, const string& str);
    std::istream& operator>>(std::istream& is, string& str);

}; // vertoker
