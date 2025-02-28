#include <string>
#include <cassert>
#include <iostream>

class TextBlock
{
public:
    TextBlock() : text{} { }
    TextBlock(const std::string& text) : text{text} { }

    // operators doesn't make sense
    
    const char& operator[](std::size_t pos)
    {
        assert(pos < text.size() && "Out of range"); // lot of blocks here
        return text[pos];
    }
    char& operator[](std::size_t pos) const
    {
        return const_cast<char&>(static_cast<const TextBlock&>(*this)[pos]);
    }

private:
    std::string text;
};

int main()
{
    TextBlock block("Hello");
    std::cout << block[0] << std::endl;

    const TextBlock cblock("Jello");
    std::cout << block[0] << std::endl;

    return 0;
}