// First variant, bad variant (leaky singleton)
// Only singlethread, potencial memory leak, no lifetime control

#include <iostream>

class Singleton
{
private:
	Singleton() {}
	static Singleton* instance;
public:
	static Singleton* getInstance()
	{
		if (instance == nullptr) // regular check
			instance = new Singleton(); // potencial memory leak
		return instance;
	}

    // no lifetime control
	
	// block copy
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	// not block move
};

Singleton* Singleton::instance = nullptr;

int main()
{
    auto s1 = Singleton::getInstance();
    auto s2 = Singleton::getInstance();

    std::cout << s1 << " " << s2 << std::endl;
    return 0;
}