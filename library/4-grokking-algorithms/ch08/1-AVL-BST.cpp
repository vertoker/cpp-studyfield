#include <iostream>
#include <memory>
#include <queue>

struct Node;
typedef std::shared_ptr<Node> NodePtr;

struct Node
{
    size_t value;
    NodePtr left = nullptr;
    NodePtr right = nullptr;

    Node(size_t value) : value{value} { }
};


int main()
{
    NodePtr root = std::make_shared<Node>(8);
    

    return 0;
}