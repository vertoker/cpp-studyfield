#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <iostream>

class Graph
{
public:
    typedef size_t NodeIndex;
    typedef std::unordered_set<NodeIndex> Links;
    typedef std::unordered_map<NodeIndex, Links> Nodes;

    inline const Nodes& getNodes() const noexcept { return nodes; }
    inline const Links& getLinks(NodeIndex node) const { return nodes.at(node); }

    NodeIndex addNode();
    bool removeNode(const NodeIndex node);
    bool containsNode(const NodeIndex node) const;

    bool addLink(const NodeIndex node1, const NodeIndex node2);
    bool removeLink(const NodeIndex node1, const NodeIndex node2);
    bool addLinkDirected(const NodeIndex node1, const NodeIndex node2);
    bool removeLinkDirected(const NodeIndex node1, const NodeIndex node2);
    
    bool containsLink(const NodeIndex node1, const NodeIndex node2) const;

private:
    Nodes nodes;
    NodeIndex nodesCounter = 0;
};

void printState(const Graph& graph);
Graph createExample1();
Graph createExample2();