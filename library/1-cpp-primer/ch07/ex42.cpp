#include <string>

class Book
{
public:
    Book(unsigned isbn)
        : Book(isbn, "") { }
    Book(unsigned isbn, const std::string& name)
        : Book(isbn, name, "") { }
    Book(unsigned isbn, const std::string& name, const std::string& author)
        : Book(isbn, name, author, "") { }
    Book(unsigned isbn, const std::string& name, const std::string& author, const std::string& pubdate)
        : isbn(isbn), name(name), author(author), pubdate(pubdate) { }
    
private:
    unsigned isbn;
    std::string name;
    std::string author;
    std::string pubdate;
};
