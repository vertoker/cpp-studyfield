#include <string>
#include <set>

class Folder;

class Message {
    friend void swap(Message &, Message &);
    friend class Folder;
public:
    explicit Message(const std::string &str = ""):contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Folder &, Folder &);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder &);
    Folder& operator=(const Folder &);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Message(const Folder&);
    void remove_from_Message();

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder &, Folder &);


#include <iostream>

void swap(Message &lhs, Message &rhs) 
{
    using std::swap;
    lhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.
    rhs.remove_from_Folders(); // Use existing member function to avoid duplicate code.
    
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    
    lhs.add_to_Folders(lhs); // Use existing member function to avoid duplicate code.
    rhs.add_to_Folders(rhs); // Use existing member function to avoid duplicate code.
}

// Message Implementation

void Message::save(Folder &f) 
{
    addFldr(&f); // Use existing member function to avoid duplicate code.
    f.addMsg(this);
}

void Message::remove(Folder &f) 
{
    remFldr(&f); // Use existing member function to avoid duplicate code.
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) 
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m) 
    : contents(m.contents), folders(m.folders) 
{
    add_to_Folders(m);
}

void Message::remove_from_Folders() 
{
    for (auto f : folders)
        f->remMsg(this);
}

Message::~Message() 
{ 
    remove_from_Folders(); 
}

Message &Message::operator=(const Message &rhs) 
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::print_debug() 
{ 
    std::cout << contents << std::endl; 
}

// Folder Implementation

void swap(Folder &lhs, Folder &rhs) 
{
    using std::swap;
    lhs.remove_from_Message();
    rhs.remove_from_Message();

    swap(lhs.msgs, rhs.msgs);
    
    lhs.add_to_Message(lhs);
    rhs.add_to_Message(rhs);
}

void Folder::add_to_Message(const Folder &f) 
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

Folder::Folder(const Folder &f) 
    : msgs(f.msgs) 
{ 
    add_to_Message(f); 
}

void Folder::remove_from_Message() 
{
    for (auto m : msgs)
        m->remFldr(this);
}

Folder::~Folder() 
{ 
    remove_from_Message(); 
}

Folder &Folder::operator=(const Folder &rhs) 
{
    remove_from_Message();
    msgs = rhs.msgs;
    add_to_Message(rhs);
    return *this;
}

void Folder::print_debug() 
{
    for (auto m : msgs)
        std::cout << m->contents << " ";
    std::cout << std::endl;
}

int main() 
{ 
    return 0;
}