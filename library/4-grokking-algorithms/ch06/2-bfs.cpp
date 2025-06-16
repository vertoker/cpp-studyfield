#include <iostream>
#include "graph.hpp"
#include <queue>

// BFS - Breadth First Search (TODO)

bool bfsRecursive(const Graph& graph, Graph::Node currentNode, Graph::Node targetNode, 
    std::unordered_set<Graph::Node>& visited, std::queue<Graph::Node>& queue, std::vector<Graph::Node>& result)
{
    auto size = queue.size();
    for (size_t i = 0; i < size; i++)
    {
        auto node = queue.front();
        queue.pop();

        for (const auto& linkedNode : graph.getLinks(currentNode))
        {
            if (visited.count(linkedNode) == 1) continue;
            if (bfsRecursive(graph, linkedNode, targetNode, visited, queue, result))
                return true;
            queue.push(linkedNode);
        }
    }
    
    result.pop_back();
    return false;
}

std::vector<Graph::Node> bfs(const Graph& graph, Graph::Node startNode, Graph::Node targetNode)
{
    std::unordered_set<Graph::Node> visited;
    std::queue<Graph::Node> queue;
    std::vector<Graph::Node> result;

    queue.push(startNode);
    result.emplace_back(startNode);

    bfsRecursive(graph, startNode, targetNode, visited, queue, result);
    //result.clear();
    return result;
}

int main()
{
    auto graph = createExample2();
    printState(graph);

    auto path1 = bfs(graph, 1, 7);
    for (auto &&i : path1)
        std::cout << i << ' ';
    std::cout << std::endl;

    auto path2 = bfs(graph, 7, 1);
    for (auto &&i : path2)
        std::cout << i << ' ';
    std::cout << std::endl;

    auto path3 = bfs(graph, 4, 3);
    for (auto &&i : path3)
        std::cout << i << ' ';
    std::cout << std::endl;
    
    
    return 0;
}