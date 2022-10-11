//Вам задан ориентированный граф с N вершинами и M ребрами
//(1 ≤ N ≤ 20000, 1 ≤ M ≤ 200000). Найдите компоненты сильной
// связности заданного графа и топологически отсортируйте его конденсацию.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    std::vector<size_t> ans;
    std::vector<size_t> comp, lst_ver;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS1(size_t vertex);

    void DFS2(size_t vertex);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices);
    visited.resize(vertices);
    ans.resize(vertices);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS1(size_t vertex) {
    visited[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS1(now);
        }
    }
    lst_ver.push_back(vertex);
}

void Graph::DFS2(size_t vertex) {
    visited[vertex] = true;
    comp.push_back(vertex);
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS2(now);
        }
    }
}


int main() {
    size_t V = 0, E = 0, quan = 1;
    std::cin >> V >> E;
    Graph g(V), g_reverse(V);
    for (size_t i = 0; i < E; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        g.addEdge(fir - 1, sec - 1);
        g_reverse.addEdge(sec - 1, fir - 1);
    }
    for (size_t i = 0; i < V; ++i) {
        if (!g.visited[i]) {
            g.DFS1(i);
        }
    }

    for (size_t i = 0; i < V; ++i) {
        size_t v = g.lst_ver[V - i - 1];
        if (!g_reverse.visited[v]) {
            g_reverse.DFS2(v);
            for (auto it = g_reverse.comp.begin(); it != g_reverse.comp.end(); ++it) {
                g_reverse.ans[*it] = quan;
            }
            ++quan;
            g_reverse.comp.clear();
        }
    }
    std::cout << quan - 1 << std::endl;
    for (size_t i = 0; i < V; ++i)
        std::cout << g_reverse.ans[i] << " ";
    return 0;
}
