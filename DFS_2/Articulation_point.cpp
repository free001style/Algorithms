//Дан неориентированный граф, который может содержать
//петли и кратные рёбра. Требуется найти все точки сочленения в нём.

#include <iostream>
#include <vector>


class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    size_t time = 0;
    std::vector<size_t> tin;
    std::vector<size_t> fup;
    std::vector<size_t> childs;
    std::vector<bool> ap;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex, bool is_root);

};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
    tin.resize(vertices + 1);
    fup.resize(vertices + 1);
    std::fill(fup.begin(), fup.end(), vertices + 1);
    childs.resize(vertices + 1);
    ap.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t now, bool is_root) {
    visited[now] = true;
    time++;
    tin[now] = time;
    for (auto neig: graph[now]) {
        if (!visited[neig]) {
            ++childs[now];
            DFS(neig, false);
            fup[now] = std::min(fup[now], fup[neig]);
            if (fup[neig] >= tin[now] && !is_root) {
                ap[now] = true;
            }
        } else {
            fup[now] = std::min(fup[now], tin[neig]);
        }
    }
}


int main() {
    size_t V = 0, E = 0;
    std::cin >> V >> E;
    Graph g(V);
    for (size_t i = 1; i < E + 1; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        if (fir != sec) {
            g.addEdge(fir, sec);
            g.addEdge(sec, fir);
        }
    }
    for (size_t i = 1; i <= V; ++i) {
        if (!g.visited[i]) {
            g.DFS(i, true);
            if (g.childs[i] >= 2) {
                g.ap[i] = true;
            }
        }
    }
    std::cout << std::count(g.ap.begin(), g.ap.end(), true) << std::endl;
    for (size_t i = 0; i < g.ap.size(); ++i) {
        if (g.ap[i]) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}
