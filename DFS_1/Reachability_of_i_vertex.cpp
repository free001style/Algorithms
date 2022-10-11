//Дан ориентированный граф, возможно, с петлями и кратными ребрами.
//Необходимо найти все вершины, из которых достижима первая вершина.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {
    visited[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS(now);
        }
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
        }
    }
    std::cout << 1 << " ";
    for (size_t i = 2; i < V + 1; ++i) {
        g.DFS(i);
        if (g.visited[1]) {
            std::cout << i << " ";
            std::fill(g.visited.begin(),g.visited.end(), false);
        }
    }
    return 0;
}
