#include <iostream>
#include <memory>
#include <queue>

struct NodeAVL;
typedef std::shared_ptr<NodeAVL> NodeAVLPtr;

struct NodeAVL
{
    int value;
    NodeAVLPtr left = nullptr;
    NodeAVLPtr right = nullptr;
    int height;

    NodeAVL(int value) : value{value} { }
};

NodeAVLPtr getMin(NodeAVLPtr node)
{
    if (!node) return nullptr;
    if (!node->left) return node;
    return getMin(node->left);
}
NodeAVLPtr getMax(NodeAVLPtr node)
{
    if (!node) return nullptr;
    if (!node->right) return node;
    return getMax(node->right);
}

int getHeight(NodeAVLPtr node)
    { return node ? node->height : -1; }
void updateHeight(NodeAVLPtr node)
    { node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1; }
int getBalance(NodeAVLPtr node)
    { return node ? getHeight(node->right) - getHeight(node->left) : 0; }
void swap(NodeAVLPtr node1, NodeAVLPtr node2) // swap only content
    { std::swap(node1->value, node2->value); }

// wtf
void rightRotate(NodeAVLPtr node)
{
    swap(node, node->left);
    NodeAVLPtr buffer = node->right;
    node->right = node->left;
    node->left = node->right->left;
    node->right->left = node->right->right;
    node->right->right = buffer;
    updateHeight(node->right);
    updateHeight(node);
}
void leftRotate(NodeAVLPtr node)
{
    swap(node, node->right);
    NodeAVLPtr buffer = node->left;
    node->left = node->right;
    node->right = node->left->right;
    node->left->right = node->left->left;
    node->left->left = buffer;
    updateHeight(node->left);
    updateHeight(node);
}
void balance(NodeAVLPtr node)
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

NodeAVLPtr search(NodeAVLPtr node, int value)
{
    if (!node) return nullptr;
    if (node->value == value) return node; // match

    return value < node->value // go deeper search
        ? search(node->left, value)
        : search(node->right, value);
}

void insert(NodeAVLPtr node, int value)
{
    if (value < node->value) // for left case
    {
        if (node->left) // if left is valid
            insert(node->left, value); // go left next
        else node->left = std::make_shared<NodeAVL>(value); // otherwise make left
    }
    else// if (node->value <= value) // for right and equal case
    {
        if (node->right)
            insert(node->right, value);
        else node->right = std::make_shared<NodeAVL>(value);
    }

    // AVL balance
    updateHeight(node);
    balance(node);
}
NodeAVLPtr erase(NodeAVLPtr node, int value)
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
            NodeAVLPtr maxInLeft = getMax(node->left);
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

void levelOrderPrint2(NodeAVLPtr node)
{
    if (!node) return;

    std::queue<NodeAVLPtr> q;
    size_t popCounter = 1;
    size_t nextCounter = 0;
    q.push(node);

    while (!q.empty())
    {
        NodeAVLPtr temp = q.front();
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
    NodeAVLPtr root = std::make_shared<NodeAVL>(8);
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