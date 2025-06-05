// Unlazy variant
// Absolutely thread-safe initialization
// May be hard for launch because it initialize in any case

#include <iostream>

class Singleton
{
private:
	Singleton() { std::cout << "ctor\n"; }
	~Singleton() { std::cout << "dtor\n"; }
    static Singleton instance;
public:
	static Singleton* getInstance() // it can return reference if make it
	{
		return &instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

Singleton Singleton::instance; // initialize before main

int main()
{
    
}