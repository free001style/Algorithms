//В рамках реформы Алголандии разрабатывается проект по оптимизации
// дорожной системы каждого города. Дорожная система каждого города
// может быть представлена в виде графа, в котором вершина соответствует
// перекрестку, а ребро графа соответствует дороге, соединяющей
// соответствующие перекрестки. За годы истории развития городов сложилась
// такая ситуация, что некоторые города получились сильно вытянутыми, и
// дорога из одного конца города в другой по дорогам может занять очень
// много времени, в то время как сами пункты назначения могут находиться
// близко географически, а прямого пути просто нет — есть только длинный
// путь в объезд по дорогам.Вам нужно среди всех кратчайших расстояний
// между всеми парами перекрестков найти максимальное расстояние.
// Так как это слишком сложно, вам предлагается сделать это для
// подмножества дорог такого, что между любыми двумя перекрестками
// существует ровно один путь.

#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;
    std::vector<size_t> ans;
    std::vector<size_t> path;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);

};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {
    visited[vertex] = true;
    path.push_back(vertex);
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS(now);
        }
    }
    if (ans.size() < path.size()) {
        ans = path;
    }
    path.pop_back();

}

int main() {
    size_t V = 0, E = 0;
    std::cin >> V;
    E = V - 1;
    Graph g(V);
    for (size_t i = 0; i < E; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        if (fir != sec) {
            g.addEdge(fir, sec);
            g.addEdge(sec, fir);
        }
    }
    g.DFS(1);
    std::fill(g.visited.begin(), g.visited.end(), false);
    g.DFS(g.ans[g.ans.size() - 1]);
    std::cout << g.ans.size() - 1;
    return 0;
}
