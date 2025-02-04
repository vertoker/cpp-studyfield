#include <iostream>
#include <forward_list>
#include <string>

void replace_or_insert(std::forward_list<std::string>& list, std::string& toFind, std::string& toAdd)
{
    auto last = list.before_begin();
    for (auto it = list.begin(); it != list.end(); last = it++)
    {
        if (*it == toFind)
        {
            list.insert_after(it, toAdd);
            return;
        }
    }
    list.insert_after(last, toAdd);
}

int main()
{
    return 0;
}