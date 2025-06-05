// Second variant, Meyers singleton - almost perfect solution
// Fix most of the problems of 1.cpp
// C++11 guarantee threead-safe initialization for local static variables
// below C++11 it's not thread-safe

#include <iostream>

class Singleton
{
private:
	Singleton() {}
public:
	static Singleton* getInstance() // it can return reference if make it
	{
        static Singleton instance;
		return &instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
    auto s1 = Singleton::getInstance();
    auto s2 = Singleton::getInstance();

    std::cout << s1 << " " << s2 << std::endl;
    return 0;
}