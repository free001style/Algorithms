//Дан ориентированный граф. Необходимо построить топологическую сортировку.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<size_t> visited1;
    std::vector<bool> visited2;
    bool cycle = false;
    std::vector<size_t> ans;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS1(size_t vertex);

    void DFS2(size_t vertex);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited1.resize(vertices + 1);
    visited2.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS1(size_t vertex) {
    visited1[vertex] = 1;
    for (size_t now: graph[vertex]) {
        if (visited1[now] == 0) {
            DFS1(now);
        } else if (visited1[now] == 1) {
            cycle = true;
            std::cout << -1;
            exit(0);
        }
    }
    visited1[vertex] = 2;
}

void Graph::DFS2(size_t vertex) {
    visited2[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited2[now]) {
            DFS2(now);
        }
    }
    ans.push_back(vertex);
}

int main() {
    size_t V = 0, E = 0;
    std::cin >> V >> E;
    Graph g(V);
    for (size_t i = 0; i < E; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        g.addEdge(fir, sec);
    }
    for (size_t i = 1; i < V + 1; ++i) {
        if (g.visited1[i] != 2) {
            g.DFS1(i);
        }
    }
    for (size_t i = 1; i < V + 1; ++i) {
        if (!g.visited2[i]) {
            g.DFS2(i);
        }
    }
    std::reverse(g.ans.begin(), g.ans.end());
    for (auto now: g.ans) {
        std::cout << now << " ";
    }
    return 0;
}
