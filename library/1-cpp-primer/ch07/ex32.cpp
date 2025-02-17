#include <iostream>
#include <string>
#include <vector>

class WindowManager;

class Screen
{
public:
    typedef std::string::size_type pos;
    friend class WindowManager;

private:
    pos cursor = 0;
    pos width = 0, height = 0;
    std::string contents;
};

class WindowManager
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen()};
};


void WindowManager::clear(ScreenIndex index)
{
    // i'm too bored for this
    screens[index].contents;
}