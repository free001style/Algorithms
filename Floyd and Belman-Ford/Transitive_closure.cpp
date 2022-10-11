//Невзвешенный ориентированный граф задан своей матрицей смежности.
// Требуется построить его транзитивное замыкание, то есть матрицу,
// в которой в i-й строке и j-м столбце находится 1, если от вершины
// i можно добраться до вершины j, и 0 - иначе.

#include <vector>
#include <iostream>

class Graph {


public:
    int num_ver = 0;
    std::vector<std::vector<int>> graph;
    std::vector<bool> used;

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
    used[vertex] = true;
    for (auto now: graph[vertex]) {
        if (!used[now]) {
            DFS(now);
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    Graph g(n);
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            int tmp = 0;
            std::cin >> tmp;
            if (tmp != 0 and i != j) {
                g.addEdge(i, j);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            g.DFS(i);
            if (g.used[j]) {
                std::cout << 1 << " ";
            } else {
                std::cout << 0 << " ";
            }
            std::fill(g.used.begin(), g.used.end(), false);
        }
        std::cout << std::endl;
    }
    return 0;
}
