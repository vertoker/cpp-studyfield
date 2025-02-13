#include <string>

class TreeNode {
public:
    TreeNode()
        : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode& rhs)
        : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right)
    { ++*count; }

    ~TreeNode() {
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
    }

    TreeNode& operator=(const TreeNode &rhs);

private:
    std::string value;
    int*        count;
    TreeNode*   left;
    TreeNode*   right;
};

class BinStrTree {
public:
    BinStrTree()
        : root(new TreeNode()) { }
    BinStrTree(const BinStrTree& bst)
        : root(new TreeNode(*bst.root)) { }
    ~BinStrTree() { delete root; }
    
    BinStrTree& operator=(const BinStrTree &bst);

private:
    TreeNode* root;
};


TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
    ++*rhs.count;
    if (--*count == 0) {
        delete left;
        delete right;
        delete count;
    }
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    count = rhs.count;
    return *this;
}

BinStrTree& BinStrTree::operator=(const BinStrTree& bst)
{
    TreeNode* new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
}

int main()
{
    return 0;
}