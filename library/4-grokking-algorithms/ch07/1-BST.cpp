#include <iostream>
#include <memory>
#include <queue>

struct Node;
typedef std::shared_ptr<Node> NodePtr;

struct Node
{
    int value;
    NodePtr left = nullptr;
    NodePtr right = nullptr;

    Node(int value) : value{value} { }
};

NodePtr getMin(NodePtr node)
{
    if (!node) return nullptr;
    if (!node->left) return node;
    return getMin(node->left);
}
NodePtr getMax(NodePtr node)
{
    if (!node) return nullptr;
    if (!node->right) return node;
    return getMax(node->right);
}
NodePtr search(NodePtr node, int value)
{
    if (!node) return nullptr;
    if (node->value == value) return node; // match

    return value < node->value // go deeper search
        ? search(node->left, value)
        : search(node->right, value);
}
void inverse(NodePtr node)
{
    if (!node) return;
    inverse(node->left);
    inverse(node->right);
    std::swap(node->left, node->right);
}

void insert(NodePtr node, int value)
{
    if (value < node->value) // for left case
    {
        if (node->left) // if left is valid
            insert(node->left, value); // go left next
        else node->left = std::make_shared<Node>(value); // otherwise make left
    }
    else// if (node->value <= value) // for right and equal case
    {
        if (node->right)
            insert(node->right, value);
        else node->right = std::make_shared<Node>(value);
    }
}
NodePtr erase(NodePtr node, int value)
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
            NodePtr maxInLeft = getMax(node->left);
            node->value = maxInLeft->value; // copy content
            // delete prev node and return child for new node
            node->left = erase(node->left, maxInLeft->value);
        }
    }
    return node; // return same node (but it may be with different value)
}

// Print BST

void levelOrderPrint(NodePtr node)
{
    if (!node) return;

    std::queue<NodePtr> q;
    q.push(node);

    while (!q.empty())
    {
        NodePtr temp = q.front();
        q.pop();
        std::cout << temp->value << ' ';

        if (temp->left)  q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}
void levelOrderPrint2(NodePtr node)
{
    if (!node) return;

    std::queue<NodePtr> q;
    size_t popCounter = 1;
    size_t nextCounter = 0;
    q.push(node);

    while (!q.empty())
    {
        NodePtr temp = q.front();
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

void preorderPrint(NodePtr node)
{
    if (!node) return;
    // for copying tree
    
    std::cout << node->value << ' ';
    preorderPrint(node->left);
    preorderPrint(node->right);
}
void inorderPrint(NodePtr node)
{
    if (!node) return;
    // for correct printing tree

    inorderPrint(node->left);
    std::cout << node->value << ' ';
    inorderPrint(node->right);
}
void postorderPrint(NodePtr node) 
{
    if (!node) return;
    // for deletion tree

    postorderPrint(node->left);
    postorderPrint(node->right);
    std::cout << node->value << ' ';
}
void reverseInorderPrint(NodePtr node)
{
    if (!node) return;
    // for inverse printing tree

    postorderPrint(node->right);
    std::cout << node->value << ' ';
    postorderPrint(node->left);
}

int main()
{
    NodePtr root = std::make_shared<Node>(8);
    insert(root, 9);
    insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);

    std::cout << std::boolalpha;
    std::cout << search(root, 6)->value << ' ';
    //std::cout << search(root, 9) << ' ';
    std::cout << getMin(root)->value << ' ';
    std::cout << getMax(root)->value << ' ';
    std::cout << std::endl;

    levelOrderPrint(root);
    std::cout << std::endl;
    preorderPrint(root);
    std::cout << std::endl;
    inorderPrint(root);
    std::cout << std::endl;
    postorderPrint(root);
    std::cout << std::endl;
    reverseInorderPrint(root);
    std::cout << std::endl;

    levelOrderPrint2(root);
    std::cout << std::endl;

    root = erase(root, 5);
    levelOrderPrint2(root);
    std::cout << std::endl;

    inverse(root);
    levelOrderPrint2(root);

    return 0;
}