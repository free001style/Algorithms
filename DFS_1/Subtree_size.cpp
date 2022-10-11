//Дано неориентированное дерево, подвешенное за вершину 1.
// Для каждой вершины подсчитайте, сколько вершин
// содержится в поддереве, подвешенном за данную вершину.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    std::vector<size_t> tin;
    std::vector<size_t> tout;
    size_t time = 1;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);

    void Previsit(size_t vertex);

    void Postvisit(size_t vertex);


};

void Graph::Previsit(size_t vertex) {
    tin[vertex] = time;
}

void Graph::Postvisit(size_t vertex) {
    tout[vertex] = ++time;
}

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
    tin.resize(vertices + 1);
    tout.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {
    visited[vertex] = true;
    Previsit(vertex);
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS(now);
        }
    }
    Postvisit(vertex);
}

int main() {
    size_t V = 0, E = 0, quan = 0;
    std::cin >> V;
    E = V - 1;
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
    for (size_t i = 1; i < V + 1; ++i) {
        std::cout << g.tout[i] - g.tin[i] << " ";
    }
    return 0;
}
