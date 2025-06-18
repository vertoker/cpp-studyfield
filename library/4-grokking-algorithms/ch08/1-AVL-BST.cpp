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
    int height;

    NodeRB(int value) : value{value} { }
};

NodeRBPtr getMin(NodeRBPtr node)
{
    if (!node) return nullptr;
    if (!node->left) return node;
    return getMin(node->left);
}
NodeRBPtr getMax(NodeRBPtr node)
{
    if (!node) return nullptr;
    if (!node->right) return node;
    return getMax(node->right);
}

int getHeight(NodeRBPtr node)
    { return node ? node->height : -1; }
void updateHeight(NodeRBPtr node)
    { node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1; }
int getBalance(NodeRBPtr node)
    { return node ? getHeight(node->right) - getHeight(node->left) : 0; }
void swap(NodeRBPtr node1, NodeRBPtr node2) // swap only content
    { std::swap(node1->value, node2->value); }

// wtf
void rightRotate(NodeRBPtr node)
{
    swap(node, node->left);
    NodeRBPtr buffer = node->right;
    node->right = node->left;
    node->left = node->right->left;
    node->right->left = node->right->right;
    node->right->right = buffer;
    updateHeight(node->right);
    updateHeight(node);
}
void leftRotate(NodeRBPtr node)
{
    swap(node, node->right);
    NodeRBPtr buffer = node->left;
    node->left = node->right;
    node->right = node->left->right;
    node->left->right = node->left->left;
    node->left->left = buffer;
    updateHeight(node->left);
    updateHeight(node);
}
void balance(NodeRBPtr node)
{
    int balance = getBalance(node);
    if (balance == -2)
    {
        // right left rotate
        if (getBalance(node->left) == 1)
            leftRotate(node->right);
        rightRotate(node);
    }
    else if (balance == 2)
    {
        // left right rotate
        if (getBalance(node->right) == -1)
            rightRotate(node->left);
        leftRotate(node);
    }
}

NodeRBPtr search(NodeRBPtr node, int value)
{
    if (!node) return nullptr;
    if (node->value == value) return node; // match

    return value < node->value // go deeper search
        ? search(node->left, value)
        : search(node->right, value);
}

void insert(NodeRBPtr node, int value)
{
    if (value < node->value) // for left case
    {
        if (node->left) // if left is valid
            insert(node->left, value); // go left next
        else node->left = std::make_shared<NodeRB>(value); // otherwise make left
    }
    else// if (node->value <= value) // for right and equal case
    {
        if (node->right)
            insert(node->right, value);
        else node->right = std::make_shared<NodeRB>(value);
    }

    // AVL balance
    updateHeight(node);
    balance(node);
}
NodeRBPtr erase(NodeRBPtr node, int value)
{
    if (!node) return nullptr; // for no valid
    // searching until node founded
    else if (value < node->value) node->left = erase(node->left, value);
    else if (node->value < value) node->right = erase(node->right, value);
    else // value is matched
    {
        // case if only 0 or 1 children has
        if (!node->left || !node->right)
            node = node->left ? node->left : node->right;
        else // case for 2 children (case for middle of BST)
        {
            // replace with left max or right min
            NodeRBPtr maxInLeft = getMax(node->left);
            node->value = maxInLeft->value; // copy content
            // delete prev node and return child for new node
            node->left = erase(node->left, maxInLeft->value);
        }
    }

    if (node) // AVL recursive balance
    {
        updateHeight(node);
        balance(node);
    }

    return node; // return same node (but it may be with different value)
}

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
        insert(root, i);
        levelOrderPrint2(root);
    }
    for (int i = 7; i >= 1; --i)
    {
        root = erase(root, i);
        levelOrderPrint2(root);
    }
    
    return 0;
}