#include "graph.hpp"

Graph::NodeIndex Graph::addNode()
{
    nodes.insert_or_assign(++nodesCounter, Links());
    return nodesCounter;
}
bool Graph::removeNode(const NodeIndex node)
{
    auto iter = nodes.find(node);
    if (iter == nodes.end()) return false;

    for (const auto& linkedNode : iter->second)
        removeLink(node, linkedNode);
    
    return true;
}
bool Graph::containsNode(NodeIndex node) const
{
    return nodes.count(node) == 1;
}

bool Graph::addLink(const NodeIndex node1, const NodeIndex node2)
{
    nodes.at(node1).insert(node2);
    nodes.at(node2).insert(node1);
    return true;
}
bool Graph::removeLink(const NodeIndex node1, const NodeIndex node2)
{
    nodes.at(node1).erase(node2);
    nodes.at(node2).erase(node1);
    return true;
}
bool Graph::addLinkDirected(const NodeIndex node1, const NodeIndex node2)
{
    nodes.at(node1).insert(node2);
    return true;
}
bool Graph::removeLinkDirected(const NodeIndex node1, const NodeIndex node2)
{
    nodes.at(node1).erase(node2);
    return true;
}

bool Graph::containsLink(const NodeIndex node1, const NodeIndex node2) const
{
    return nodes.at(node1).count(node2) == 1;
}

void printState(const Graph& graph)
{
    std::cout << "Graph state" << std::endl;
    for (const auto& pair : graph.getNodes())
    {
        std::cout << "Node " << pair.first << ": ";
        for (const auto& linkedNode : pair.second)
        {
            std::cout << linkedNode << ' ';
        }
        std::cout << std::endl;
    }
}

Graph createExample1()
{
    Graph graph;
    auto node1 = graph.addNode();
    auto node2 = graph.addNode();
    auto node3 = graph.addNode();

    graph.addLink(node1, node2);
    graph.addLink(node2, node3);
    return graph;
}

Graph createExample2()
{
    Graph graph;
    auto node1 = graph.addNode();
    auto node2 = graph.addNode();
    auto node3 = graph.addNode();
    auto node4 = graph.addNode();
    auto node5 = graph.addNode();
    auto node6 = graph.addNode();
    auto node7 = graph.addNode();

    graph.addLinkDirected(node1, node2);
    graph.addLinkDirected(node2, node3);
    graph.addLinkDirected(node1, node4);
    graph.addLinkDirected(node4, node3);
    graph.addLinkDirected(node4, node5);
    graph.addLinkDirected(node4, node6);
    graph.addLinkDirected(node6, node5);
    graph.addLinkDirected(node6, node7);
    return graph;
}
