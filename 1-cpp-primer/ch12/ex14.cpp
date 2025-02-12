#include <iostream>
#include <string>
#include <memory>

struct connection {
    std::string ip;
    uint16_t port;

    connection(std::string ip, uint16_t port)
        : ip(std::move(ip)), port(port) { }
};

struct destination {
    std::string ip;
    uint16_t port;

    destination(std::string ip, uint16_t port)
        : ip(std::move(ip)), port(port) { }
};

connection connect(destination* pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

int main()
{
    // https://www.youtube.com/watch?v=zPFp2nWwaRU
    destination dest("92.52.15.200", 8080);

    connection conn = connect(&dest);
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;

    return 0;
}