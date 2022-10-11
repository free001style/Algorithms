//От вас требуется определить вес минимального остовного
// дерева для неориентированного взвешенного связного графа.

#include <iostream>
#include <vector>
#include <tuple>

class Graph {


public:
    int num_ver = 0;
    std::vector <std::pair<int, std::pair < int, int>>>
    graph;
    std::vector<int> weight;
    std::vector<int> p;

    Graph(int V);

    void addEdge(int u, int v, int w);

    int find(int ver);

    void unire(int u, int v);

    void Kruscala();

};

Graph::Graph(int vertices) {
    num_ver = vertices;
    p.resize(num_ver);
    for (int i = 0; i < num_ver; ++i) {
        p[i] = i;
    }
}

void Graph::addEdge(int u, int v, int w) {
    graph.push_back({w, {u, v}});
}

int Graph::find(int ver) {
    if (ver == p[ver])
        return ver;
    else
        return find(p[ver]);
}

void Graph::unire(int u, int v) {
    p[u] = p[v];
}

void Graph::Kruscala() {
    std::sort(graph.begin(), graph.end());
    for (auto now: graph) {
        if (find(now.second.first) != find(now.second.second)) {
            weight.push_back(now.first);
            unire(find(now.second.first), find(now.second.second));
        }
    }
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        g.addEdge(--u, --v, w);
    }
    g.Kruscala();
    long long sum = 0;
    for (auto now: g.weight) {
        sum += now;
    }
    std::cout << sum;
}
