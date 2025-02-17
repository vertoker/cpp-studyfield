#include "string1.h"

#define END_STR '\0';

vertoker::string::string(const char* str, std::size_t length)
    : cstr{new char[length + 1]}
{
    memcpy(cstr, str, length);
    cstr[length] = END_STR;
}
vertoker::string::string(const char* str)
    : string(str, strlen(str))
{

}
vertoker::string::string()
    : cstr{new char[1]}
{
    cstr[0] = END_STR;
}

vertoker::string::~string()
{
    delete[] cstr;
}

// copy

vertoker::string::string(const string &other)
    : string(other.cstr)
{

}
vertoker::string& vertoker::string::operator=(const string& other)
{
    if (this == &other) return *this;

    string temp(other);
    std::swap(cstr, temp.cstr); // TODO
    return *this;
}

// move

vertoker::string::string(string&& other)
    : string(std::exchange(other.cstr, nullptr)) // TODO
{
    
}
vertoker::string& vertoker::string::operator=(string&& other)
{
    string temp(std::move(other)); // TODO
    std::swap(cstr, temp.cstr); // TODO
    return *this;
}

// other

vertoker::string& vertoker::string::operator+=(const string& other)
{
    string temp = *this + other;
    std::swap(cstr, temp.cstr); // TODO
    return *this;
}

// external

vertoker::string& vertoker::operator+(const string& str1, const string& str2)
{
    size_t len1 = str1.length();
    size_t len2 = len1 + str2.length();
    char* concat_cstr = new char[len2 + 1];

    strcpy(concat_cstr, str1.c_str());
    strcpy(concat_cstr + len1, str2.c_str());
    concat_cstr[len2] = END_STR;

    string result(std::move(concat_cstr)); // TODO
    return result;
}
std::ostream& vertoker::operator<<(std::ostream& os, const string& str)
{
    os << str.c_str();
    return os;
}
// https://stackoverflow.com/questions/69803296/overloading-istream-operator
std::istream& vertoker::operator>>(std::istream& is, string& str)
{
    static const int max_size = 260;
    static char buffer[max_size];
    is.getline(buffer, max_size);
    
    size_t size = strlen(buffer);
    char* newstr = new char[size + 1];
    strcpy(newstr, buffer);
    newstr[size] = END_STR;

    // shit code ON
    string temp(std::move(newstr)); // TODO
    std::swap(str, temp); // TODO
    // shit code OFF

    return is;
}
