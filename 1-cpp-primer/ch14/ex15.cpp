#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate, unsigned number):no_(no), name_(name), author_(author), pubdate_(pubdate), number_(number) { }
    Book(std::istream &in) { in >> *this; }

    Book& operator+=(const Book&);

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
    unsigned number_;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);
Book operator+(const Book&, const Book&);

std::istream& operator>>(std::istream &in, Book &book)
{
    in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
    return in;
}
std::ostream& operator<<(std::ostream &out, const Book &book)
{
    out << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_ << " " << book.number_ << std::endl;
    return out;
}
bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.no_ == rhs.no_;
}
bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}
bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.no_ < rhs.no_;
}
bool operator>(const Book &lhs, const Book &rhs)
{
    return rhs < lhs;
}

Book& Book::operator+=(const Book &rhs)
{
    if (rhs == *this)
        this->number_ += rhs.number_;

    return *this;
}
Book operator+(const Book &lhs, const Book &rhs)
{
    Book book = lhs;
    book += rhs;
    return book;
}

int main()
{
    Book cp5_1(12345, "CP5", "Lippmen", "2012", 2);
    Book cp5_2(12345, "CP5", "Lippmen", "2012", 4);

    std::cout << cp5_1 + cp5_2 << std::endl;
}