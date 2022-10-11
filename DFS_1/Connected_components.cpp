//Дан неориентированный невзвешенный граф. Необходимо
// посчитать количество его компонент связности и вывести их.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    std::vector<size_t> comp;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);

    void finder();

    size_t count();
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
    comp.push_back(vertex);
    for (size_t now: graph[vertex]) {
        if (!visited[now])
            DFS(now);
    }
}

void Graph::finder() {
    for (size_t i = 1; i < num_ver + 1; ++i)
        visited[i] = false;
    for (size_t i = 1; i < num_ver + 1; ++i)
        if (!visited[i]) {
            comp.clear();
            DFS(i);
            std::cout << comp.size() << std::endl;
            for (auto now: comp) {
                std::cout << now << ' ';
            }
            std::cout << std::endl;
        }
}

size_t Graph::count() {
    size_t quan = 0;
    for (size_t i = 1; i < num_ver + 1; ++i)
        visited[i] = false;
    for (size_t i = 1; i < num_ver + 1; ++i)
        if (!visited[i]) {
            comp.clear();
            DFS(i);
            ++quan;
        }
    return quan;
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
    std::cout << g.count() << std::endl;
    g.finder();
    return 0;
}
