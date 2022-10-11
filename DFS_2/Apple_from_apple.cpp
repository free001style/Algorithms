//У Пети в саду растет яблоня. Воодушевленный историей об Исааке Ньютоне,
// который, как известно, открыл закон всемирного тяготения после того,
// как ему на голову упало яблоко, Петя с целью повысить свою успеваемость
// по физике часто сидит под яблоней. Однако, поскольку по физике у Пети
//твердая тройка, яблоки с его яблони падают следующим образом. В какой-то
//момент одно из яблок отрывается от ветки, на которой оно висит, и начинает
// падать строго вниз. Если в некоторый момент оно задевает другое яблоко, то
// то тоже отрывается от своей ветки и начинает падать вниз, при этом первое
// яблоко не меняет направление своего падения. Вообще, если любое падающее
// яблоко заденет другое яблоко на своем пути, то оно также начнет падать.
//Таким образом, в любой момент каждое яблоко либо висит на ветке, либо падает
// строго вниз, причем все яблоки кроме первого, чтобы начать падать, должны
// сначала соприкоснуться с каким-либо другим падающим яблоком.
//Выясните, какие яблоки упадут с Петиной яблони.

#include <iostream>
#include <vector>

class Graph {
public:
    size_t num_ver = 0;
    std::vector <std::vector<size_t>> graph;
    std::vector<bool> visited1;
    std::vector <size_t> order;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited1.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {
    visited1[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited1[now]) {
            DFS(now);
        }
    }
    order.push_back(vertex);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector <std::vector<int>> apples(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        int x = 0, y = 0, z = 0, r = 0;
        std::cin >> x >> y >> z >> r;
        z -= r;
        apples[i] = {x, y, z, r};
    }
    Graph g(n + 1);
    for (size_t i = 1; i < n + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            if (i != j) {
                if ((apples[i][0] - apples[j][0]) * (apples[i][0] - apples[j][0]) +
                    (apples[i][1] - apples[j][1]) * (apples[i][1] - apples[j][1]) <=
                    (apples[i][3] + apples[j][3]) * (apples[i][3] + apples[j][3]) and apples[j][2] < apples[i][2]) {
                    g.addEdge(i, j);
                }
            }
        }
    }
    g.DFS(1);
    std::reverse(g.order.begin(), g.order.end());
    std::cout << g.order.size() << std::endl;
    for (auto now: g.order) {
        std::cout << now << " ";
    }
    return 0;
}