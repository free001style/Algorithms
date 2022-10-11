//Дан неориентированный граф, который может содержать
// петли и кратные рёбра. Требуется найти все мосты в нём.

//TL 13

#include <iostream>
#include <vector>
#include <tuple>
#include <map>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    std::vector<std::pair<size_t, size_t>> ans;
    size_t time = 0;
    std::vector<size_t> tin;
    std::vector<size_t> fup;
    std::map<std::pair<size_t, size_t>, bool> crat;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex, size_t color);

    void IS_BRIDGE(size_t v, size_t to);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
    tin.resize(vertices + 1);
    fup.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex, size_t p = -1) {
    visited[vertex] = true;
    tin[vertex] = fup[vertex] = time++;
    for (auto now: graph[vertex]) {
        if (now == p) continue;
        if (visited[now])
            fup[vertex] = std::min(fup[vertex], tin[now]);
        else {
            DFS(now, vertex);
            fup[vertex] = std::min(fup[vertex], fup[now]);
            if (fup[now] > tin[vertex])
                IS_BRIDGE(vertex, now);
        }
    }
}

void Graph::IS_BRIDGE(size_t v, size_t to) {
    if (!crat[std::pair(v, to)]) {
        ans.push_back({v, to});
    }
}

int main() {
    size_t V = 0, E = 0;
    std::cin >> V >> E;
    Graph g(V);


    std::map<size_t, std::pair<size_t, size_t>> ord;
    for (size_t i = 1; i < E + 1; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        ord[i] = std::pair(fir, sec);
        if (fir != sec) {
            if (g.crat.find(std::pair(fir, sec)) != g.crat.end()) {
                g.crat[std::pair(fir, sec)] = true;
            } else {
                g.crat[std::pair(fir, sec)] = false;
            }
            g.addEdge(fir, sec);
            g.addEdge(sec, fir);
        }
    }
    for (size_t i = 1; i < V + 1; ++i) {
        if (!g.visited[i]) {
            g.DFS(i);
        }
    }
    std::vector<size_t> ans;
    std::cout << g.ans.size() << std::endl;
    if (!g.ans.empty()) {
        for (auto now: g.ans) {
            for (size_t i = 1; i < ord.size() + 1; ++i) {
                if (ord[i] == now or ord[i] == std::pair(now.second, now.first)) {
                    ans.push_back(i);
                    break;
                }
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    for (auto now: ans) {
        std::cout << now << std::endl;
    }
    return 0;
}
