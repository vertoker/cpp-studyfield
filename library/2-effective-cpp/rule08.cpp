// 8. Prevent exceptions from leaving destructors

#include <iostream>
#include <assert.h>

class DBConnection
{
public:
    DBConnection() { }
    ~DBConnection() { }
    static DBConnection create() {
        return DBConnection();
    }
    void close() {
        assert(!closed); // guess this error represent hard to maintain error
        std::cout << "close() DBConnection" << std::endl;
        closed = true;
    }
    inline bool isClosed() { return closed; }

private:
    bool closed = false;
};

class DBConn
{
public:
    DBConn() : db{DBConnection::create()} { }
    ~DBConn() { close(); }
    
    /*void close() { // provides error
        db.close();
    }*/
    void close() {  // not provides error
        if (!db.isClosed())
            db.close();
    }

private:
    DBConnection db;
};

int main()
{
    DBConn conn;
    conn.close();
    
    return 0;
}