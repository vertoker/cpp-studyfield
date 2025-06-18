#include "../common/graph.hpp"
#include <queue>

// BFS - Breadth First Search
// Without traced path, too complicated for me, DFS is much simpler in that
// https://stackoverflow.com/questions/62803211/how-to-reconstruct-paths-using-bfs

bool bfsRecursive(const Graph& graph, Graph::Node targetNode, 
    std::unordered_set<Graph::Node>& visited, std::queue<Graph::Node>& queue)
{
    auto counter = queue.size();
    while (counter != 0)
    {
        auto node = queue.front();
        queue.pop();

        if (node == targetNode) return true;
        
        for (const auto& linkedNode : graph.getLinks(node))
        {
            if (visited.count(linkedNode) == 1) continue;
            queue.push(linkedNode);
            visited.insert(linkedNode);
        }

        --counter;
    }

    return queue.size() != 0 && bfsRecursive(graph, targetNode, visited, queue);
}

bool bfs(const Graph& graph, Graph::Node startNode, Graph::Node targetNode)
{
    std::unordered_set<Graph::Node> visited;
    std::queue<Graph::Node> queue;

    queue.push(startNode);
    visited.insert(startNode);
    return bfsRecursive(graph, targetNode, visited, queue);
}

int main()
{
    auto graph = createExample2();
    printState(graph);

    auto has1 = bfs(graph, 1, 7);
    auto has2 = bfs(graph, 7, 1);
    auto has3 = bfs(graph, 4, 3);
    
    std::cout << std::boolalpha;
    std::cout << has1 << ' ';
    std::cout << has2 << ' ';
    std::cout << has3 << ' ';

    return 0;
}