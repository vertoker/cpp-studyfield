#include <cstring>
#include <iostream>

class String
{
public:
    String();
    String(const char* s);
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();

    const char* c_str() const { return data; }

private:
    char* data;
    size_t capacity;
    size_t size;
};

String::String()
{
    size = capacity = 1;
    data = new char[1];
    data[0] = '\0';
}
String::String(const char* s)
{
    size = strlen(s) + 1;
    capacity = size;
    data = new char[size];
    memcpy(data, s, size);
}
String::String(const String& other) : size(other.size), capacity(other.capacity)
{
    data = new char[size];
    memcpy(data, other.data, size);
}
String::String(String&& other) noexcept : size(other.size), capacity(other.capacity), data(data)
{
    other.size = 0;
    other.capacity = 0;
}

String& String::operator=(const String& other)
{
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = other.data;
    memcpy(data, other.data, size);

    return *this;
}
String& String::operator=(String&& other)
{
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = other.data;

    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;

    return *this;
}

String::~String()
{
	size = 0;
	capacity = 0;
    delete[] data;
}

int main()
{
    String str;
    String str2("12321");

    std::cout << str2.c_str();

    return 0;
}