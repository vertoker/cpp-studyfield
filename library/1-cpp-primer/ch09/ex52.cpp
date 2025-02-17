#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string expression{ "This is (kostya)." };
    bool bSeen = false;
    std::stack<char> stk;

    for (const auto &s : expression)
    {
        if (s == '(') { bSeen = true; continue; }
        else if (s == ')') bSeen = false;
        
        if (bSeen) stk.push(s);
    }
    
    std::string repstr;
    while (!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }
    
    expression.replace(expression.find("(") + 1, repstr.size(), repstr);
    
    std::cout << expression << std::endl;
    
    return 0;
}