//Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной заданной вершины до другой.

#include <iostream>
#include <vector>

int main() {
    int INF = 1e9;
    int n = 0, from = 0, fin = 0;
    std::cin >> n >> from >> fin;
    from--;
    fin--;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num > 0) {
                graph[i].push_back({j, num});
            }
        }
    }

    std::vector<int> d(n, INF), p(n);
    d[from] = 0;
    std::vector<bool> u(n);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first,
                    len = graph[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    if (d[fin] < INF) {
        std::cout << d[fin];
    } else {
        std::cout << -1;
    }
    return 0;
}
