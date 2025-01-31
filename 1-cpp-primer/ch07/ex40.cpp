#include <string>

class Book
{
public:
    Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& pubdate)
        : isbn(isbn), name(name), author(author), pubdate(pubdate) { }
    
private:
    unsigned isbn;
    std::string name;
    std::string author;
    std::string pubdate;
};

class Data
{
    int i;
    double d;
public:
    Data(int i) : Data(i, 0.0) { }
    Data(int i, double d) : i(i), d(d) {}
};
