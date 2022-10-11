//Во время контрольной работы профессор Флойд заметил,
// что некоторые студенты обмениваются записками.
// Сначала он хотел поставить им всем двойки, но в
// тот день профессор был добрым, а потому решил разделить
// студентов на две группы: списывающих и дающих списывать, и
// поставить двойки только первым. У профессора записаны
// все пары студентов, обменявшихся записками. Требуется
// определить, сможет ли он разделить студентов на две группы
// так, чтобы любой обмен записками осуществлялся от студента одной
// группы студенту другой группы.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<size_t> visited;
    std::vector<size_t> comp;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex, size_t color);

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

void Graph::DFS(size_t vertex, size_t color) {
    visited[vertex] = color;
    for (size_t now: graph[vertex]) {
        if (visited[now] == 0) {
            DFS(now, 3 - color);
        } else if (visited[now] == color) {
            std::cout << "NO";
            exit(0);
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
            g.addEdge(sec, fir);
        }
    }
    for (size_t i = 1; i < V + 1; ++i) {
        if (g.visited[i] == 0) {
            g.DFS(i, 1);
        }
    }
    std::cout << "YES";
    return 0;
}
