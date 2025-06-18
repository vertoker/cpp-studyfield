#include "../common/graph.hpp"

// DFS - Depth First Search

bool dfsRecursive(const Graph& graph, Graph::Node currentNode, Graph::Node targetNode, std::unordered_set<Graph::Node>& visited, std::vector<Graph::Node>& result)
{
    visited.insert(currentNode);
    result.emplace_back(currentNode);
    if (currentNode == targetNode) return true;

    for (const auto& linkedNode : graph.getLinks(currentNode))
    {
        if (visited.count(linkedNode) == 1) continue;
        if (dfsRecursive(graph, linkedNode, targetNode, visited, result))
            return true;
    }

    result.pop_back();
    return false;
}

std::vector<Graph::Node> dfs(const Graph& graph, Graph::Node startNode, Graph::Node targetNode)
{
    std::unordered_set<Graph::Node> visited;
    std::vector<Graph::Node> result;
    dfsRecursive(graph, startNode, targetNode, visited, result);
    //result.clear();
    return result;
}

int main()
{
    auto graph = createExample2();
    printState(graph);

    auto path1 = dfs(graph, 1, 7);
    for (auto &&i : path1)
        std::cout << i << ' ';
    std::cout << std::endl;

    auto path2 = dfs(graph, 7, 1);
    for (auto &&i : path2)
        std::cout << i << ' ';
    std::cout << std::endl;

    auto path3 = dfs(graph, 4, 3);
    for (auto &&i : path3)
        std::cout << i << ' ';
    std::cout << std::endl;
    
    
    return 0;
}