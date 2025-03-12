#include <cstring>

class Str {
	char* ptr;
public:
	Str() : ptr{new char[1024]} { }
	~Str() { delete ptr; }
	
	Str& operator==(Str&& other) {
		// if (this == &other) return *this; // guess maybe 
		
		delete ptr;
        ptr = other.ptr;
		return *this;
	}
};