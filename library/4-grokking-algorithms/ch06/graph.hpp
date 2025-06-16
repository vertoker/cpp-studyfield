#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

class Graph
{
public:
    typedef size_t Node;
    typedef std::unordered_set<Node> Links;
    typedef std::unordered_map<Node, Links> Nodes;

    inline const Nodes& getNodes() const noexcept { return nodes; }
    inline const Links& getLinks(Node node) const { return nodes.at(node); }

    Node addNode();
    bool removeNode(const Node node);
    bool containsNode(const Node node) const;

    bool addLink(const Node node1, const Node node2);
    bool removeLink(const Node node1, const Node node2);
    bool addLinkDirected(const Node node1, const Node node2);
    bool removeLinkDirected(const Node node1, const Node node2);
    
    bool containsLink(const Node node1, const Node node2) const;

private:
    Nodes nodes;
    Node nodesCounter = 0;
};

void printState(const Graph& graph);
Graph createExample1();
Graph createExample2();