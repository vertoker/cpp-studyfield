#include <iostream>
#include <memory>
#include <queue>

struct NodeRB;
typedef std::shared_ptr<NodeRB> NodeRBPtr;

struct NodeRB
{
    int value;
    NodeRBPtr left = nullptr;
    NodeRBPtr right = nullptr;
    NodeRBPtr parent = nullptr;
    bool black = true;

    NodeRB(int value) : value{value} { }
};

void levelOrderPrint2(NodeRBPtr node)
{
    if (!node) return;

    std::queue<NodeRBPtr> q;
    size_t popCounter = 1;
    size_t nextCounter = 0;
    q.push(node);

    while (!q.empty())
    {
        NodeRBPtr temp = q.front();
        q.pop(); --popCounter;
        
        if (temp)
        {
            std::cout << temp->value << ' ';
            
            q.push(temp->left);
            q.push(temp->right);
            nextCounter += 2;
        }
        else std::cout << "* ";
        
        if (popCounter == 0)
        {
            popCounter = nextCounter;
            nextCounter = 0;
            std::cout << std::endl;
        }
    }
}

int main()
{
    NodeRBPtr root = std::make_shared<NodeRB>(8);
    levelOrderPrint2(root);

    for (int i = 7; i >= 1; --i)
    {
        //insert(root, i);
        //levelOrderPrint2(root);
    }
    for (int i = 7; i >= 1; --i)
    {
        //root = erase(root, i);
        //levelOrderPrint2(root);
    }
    
    return 0;
}