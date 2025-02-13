#include <string>

class HasPtr {
public:
    HasPtr(const std::string& s = std::string())
        : ps(new std::string(s)), i(0) { }
    ~HasPtr() { delete ps; }
    
    HasPtr(const HasPtr& hp)
        : ps(new std::string(*hp.ps)), i(hp.i) { }
    
    HasPtr& operator=(const HasPtr &hp)
    {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        
        ps = new_p;
        i = hp.i;
        
        return *this;
    }
private:
    std::string* ps;
    int i;
};
