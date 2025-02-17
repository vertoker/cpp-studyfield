#include <iostream>
#include <string>

class Screen
{
public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type;

    Screen() = default;
    Screen(pos width, pos height, char defaultChar)
        : width(width), height(height), contents(width * height, defaultChar) { }
    
    char get() const { return contents[cursor]; }
    inline char get(pos coordX, pos coordY) const;
    Screen& move(pos coordX, pos coordY);

private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
};

inline Screen& Screen::move(pos coordX, pos coordY)
{
    pos row = coordY * width;
    cursor = row + coordX;
    return *this;
}
char Screen::get(pos coordX, pos coordY) const
{
    pos index = coordY * width + coordX;
    return contents[index];
}

int main()
{
    Screen screen1, screen2;
    screen1 = screen2; // allow because copy constructor by default not force explicit
    return 0;
}