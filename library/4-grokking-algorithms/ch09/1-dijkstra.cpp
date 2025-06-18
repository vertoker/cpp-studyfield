#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

// https://lliçons.jutge.org/cpp/eda/weighted-graphs/index.html

using node = int;
using weight = double;
using arc = std::pair<weight, node>;
using WAdjacencyList = std::vector<arc>;
using WGraph = std::vector<WAdjacencyList>;

const weight infinity = std::numeric_limits<weight>::infinity();
const node None = -1;

std::vector<node> dijkstra(const WGraph& weightedGraph, node startNode, node endNode)
{
    size_t nodesCount = weightedGraph.size();
    std::vector<node>   parents(nodesCount, None);       // for each node, its parent node
    std::vector<weight> distances(nodesCount, infinity); // for each node, its minimum distance from startNode
    std::vector<bool>   visited(nodesCount, false);      // subset of nodes with optimal distance
    std::priority_queue<arc, std::vector<arc>, std::greater<arc>> pqToPass;

    distances[startNode] = 0;
    pqToPass.push({0, startNode});

    while (not pqToPass.empty())
    {
        node srcNode = pqToPass.top().second;
        pqToPass.pop();

        if (visited[srcNode]) continue;
        visited[srcNode] = true;

        for (auto& arc : weightedGraph[srcNode])
        {
            weight edgeWeight = arc.first;
            node dstNode = arc.second;

            // override if distance (or more optimal distance) to the node is founded
            if (distances[dstNode] > distances[srcNode] + edgeWeight)
            {
                distances[dstNode] = distances[srcNode] + edgeWeight;
                parents[dstNode] = srcNode;
                pqToPass.push({distances[dstNode], dstNode}); // required to check
            }
        }
    }

    std::vector<node> path;
    node ptrNode = endNode;

    while (ptrNode != startNode)
    {
        if (parents[ptrNode] == None) break;
        path.emplace_back(ptrNode);
        ptrNode = parents[ptrNode];
    }
    path.emplace_back(startNode);

    std::reverse(path.begin(), path.end());

    return path;
}

int main()
{
    WGraph weightedGraph = {
        {{6, 1}, {2, 2}}, // 0-A
        {{1, 3}}, // 1-B
        {{3, 1}, {5, 3}}, // 2-C
        {} // 3-D
    };

    auto path = dijkstra(weightedGraph, 0, 3);

    for (auto &&i : path)
        std::cout << i << ' ';
    std::cout << std::endl;
    
    return 0;
}