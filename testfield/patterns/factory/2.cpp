
#include <iostream>

class Document
{
public:
    virtual ~Document() { }
    virtual void open() = 0;
    virtual void save() = 0;
};
class TxtDocument : public Document
{
public:
    void open() override { std::cout << "open txt\n"; }
    void save() override { std::cout << "save txt\n"; }
};
class HtmlDocument : public Document
{
public:
    void open() override { std::cout << "open html\n"; }
    void save() override { std::cout << "save html\n"; }
};

class DocumentManager
{
public:
    virtual Document* createDocument() = 0; // declare of factory method
};
class TxtDocumentManager : public DocumentManager
{
public:
    Document* createDocument() override { return new TxtDocument(); } // define factory method for txt
};
class HtmlDocumentManager : public DocumentManager
{
public:
    Document* createDocument() override { return new HtmlDocument(); } // define factory method for html
};

int main()
{
    HtmlDocumentManager manager;
    auto doc = manager.createDocument();
    doc->open();
    delete doc;
}