//Дан неориентированный граф, возможно, с петлями и кратными ребрами.
// Необходимо построить компоненту связности, содержащую первую вершину.

#include <iostream>
#include <vector>

using namespace std;

class Graph {


public:
    vector<vector<size_t>> graph;
    vector<bool> visited;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);
};

Graph::Graph(size_t vertices) {
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {

    visited[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited[now])
            DFS(now);
    }
}

int main() {
    size_t V = 0, E = 0, quan = 0;
    std::cin >> V >> E;
    Graph g(V);
    for (size_t i = 0; i < E; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        if (fir != sec) {
            g.addEdge(fir, sec);
            g.addEdge(sec, fir);
        }
    }
    g.DFS(1);
    for (size_t now: g.visited) {
        if (now) {
            ++quan;
        }
    }
    std::cout << quan << std::endl;
    for (size_t i = 1; i < g.visited.size(); ++i) {
        if (g.visited[i]) {
            std::cout << i << " ";
        }
    }
    return 0;
}
