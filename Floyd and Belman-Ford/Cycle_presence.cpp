//Дан ориентированный граф. Требуется определить, есть ли в нем цикл.

#include <vector>
#include <iostream>

class Graph {


public:
    int num_ver = 0;
    std::vector<std::vector<int>> graph;
    std::vector<int> used;

    Graph(int V);

    void addEdge(int src, int dest);

    void DFS(int);
};

Graph::Graph(int vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    used.resize(vertices + 1);
}

void Graph::addEdge(int src, int dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(int vertex) {
    used[vertex] = 1;
    for (int now: graph[vertex]) {
        if (used[now] == 0) {
            DFS(now);
        } else if (used[now] == 1) {
            std::cout << 1;
            exit(0);
        }
    }
    used[vertex] = 2;
}

int main() {
    int n = 0;
    std::cin >> n;
    Graph g(n);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int tmp = 0;
            std::cin >> tmp;
            if (tmp != 0) {
                g.addEdge(i, j);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (!g.used[i]) {
            g.DFS(i);
            std::fill(g.used.begin(), g.used.end(), 0);
        }
    }
    std::cout << 0;
    return 0;
}
