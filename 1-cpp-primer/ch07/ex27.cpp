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
    Screen& set(char ch);
    Screen& move(pos coordX, pos coordY);

    Screen& display(std::ostream& os) { do_display(os); return *this; }
    const Screen& display(std::ostream& os) const { do_display(os); return *this; }

private:
    void do_display(std::ostream& os) const;

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
inline Screen& Screen::set(char ch)
{
    contents[cursor] = ch;
    return *this;
}
void Screen::do_display(std::ostream& os) const
{
    // just prints string in console is not work properly, I decide to rewrite it
    size_t counter = 0;
    while (counter < contents.size())
    {
        os << contents[counter];
        ++counter;
        if (counter % width == 0)
            os << '\n';
    }
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;
    myScreen.display(std::cout);
    return 0;
}