//Дан неориентированный граф. Требуется определить,
// есть ли в нем цикл, и, если есть, вывести его.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<size_t> visited;
    std::vector<size_t> ans;
    bool cycle = false;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex, size_t color);

};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex, size_t p) {
    if (cycle) {
        return;
    }
    visited[vertex] = 1;
    ans.push_back(vertex);
    for (size_t now: graph[vertex]) {
        if (now == p) {
            continue;
        }
        if (visited[now] == 1) {
            ans.push_back(now);
            cycle = true;
            return;
        } else {
            DFS(now, vertex);
        }
        if (cycle) return;
    }
    visited[vertex] = 2;
    ans.pop_back();
}

int main() {
    size_t V = 0, tmp = 0;
    std::cin >> V;
    Graph g(V);
    for (size_t i = 1; i < V + 1; ++i) {
        for (size_t j = 1; j < V + 1; ++j) {
            std::cin >> tmp;
            if (tmp == 1) {
                g.addEdge(i, j);

            }
        }
    }
    for (size_t i = 1; i < V + 1; ++i) {
        if (g.visited[i] == 0) {
            g.DFS(i, 0);
            if (g.cycle) {
                break;
            }
        }
    }
    if (g.cycle) {
        std::cout << "YES" << std::endl;
        std::vector<size_t> answer;
        answer.push_back(g.ans.back());
        size_t i = g.ans.size() - 2;
        while (g.ans[i] != g.ans.back()) {
            answer.push_back(g.ans[i]);
            --i;
        }



        std::cout << answer.size() << std::endl;

        for (size_t now: answer) {
            std::cout << now << " ";
        }
    } else {
        std::cout << "NO" << std::endl;
    }
}
