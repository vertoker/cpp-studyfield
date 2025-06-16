#include <iostream>
#include <vector>
#include <memory>
#include <string>

template <class T, class Alloc = std::allocator<T>>
class Set
{
    struct Node;

    typedef std::shared_ptr<Node> NodePtr;

    struct Node
    {
        T value;
        NodePtr next;
    };

    std::vector<NodePtr, Alloc> data;
    
public:
    bool insert(const T& value)
    {
        size_t hash = std::hash<std::string>{}(value);
        size_t index = hash % data.size(); // can be divided by 0

        NodePtr prevNode = nullptr;
        NodePtr node = data[index];

        while (node.get() != nullptr)
        {
            if (node->value == value)
                return false;
            prevNode = node;
            node = node->next;
        }

        node = std::make_shared<Node>();
        node->value = value;

        if (prevNode)
            prevNode->next = node;
        else data[index] = node;
        
        return true;
    }
    bool contains(const T& value)
    {
        size_t hash = std::hash<std::string>{}(value);
        size_t index = hash % data.size(); // can be divided by 0

        NodePtr node = data[index];
        while (node.get() != nullptr)
        {
            if (node->value == value) return true;
            if (node->next == nullptr) return false;
            node = node->next;
        }

        return false;
    }
    bool remove(const T& value)
    {
        size_t hash = std::hash<std::string>{}(value);
        size_t index = hash % data.size(); // can be divided by 0

        NodePtr prevNode = nullptr;
        NodePtr node = data[index];

        while (node.get() != nullptr)
        {
            if (node->value == value) break;
            prevNode = node;
            node = node->next;
        }

        if (node.get() == nullptr) return false;

        if (prevNode)
            prevNode->next.reset();
        else data[index].reset();
        
        return true;
    }

    void printStatus()
    {
        std::cout << "status" << std::endl;
        for (size_t i = 0; i < data.size(); i++)
        {
            std::cout << "index " << i << ": ";

            NodePtr node = data[i];
            while (node.get() != nullptr)
            {
                std::cout << node->value << ' ';
                node = node->next;
            }

            std::cout << std::endl;
        }
        
    }
    
    void resize(size_t size)
    {
        data.resize(size);
    }
};

int main()
{
    Set<std::string> set;
    set.resize(2);
    set.printStatus();

    std::cout << std::boolalpha;

    std::cout << set.contains("1") << std::endl;
    set.insert("1");
    set.printStatus();
    std::cout << set.contains("1") << std::endl;

    set.insert("2");
    set.printStatus();

    std::cout << set.contains("3") << std::endl;
    set.insert("3");
    set.printStatus();
    std::cout << set.contains("3") << std::endl;
    set.remove("3");
    set.printStatus();
    std::cout << set.contains("3") << std::endl;

    return 0;
}