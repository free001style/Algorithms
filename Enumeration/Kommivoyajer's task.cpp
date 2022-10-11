//Неориентированный взвешенный граф задан матрицей смежности. Необходимо найти кратчайший цикл,
// который начинается и заканчивается в вершине номер 1 и проходит через все вершины по одному разу.

#include <iostream>
#include <vector>

const int inf = 1E9;
int t[1 << 11][11];

struct Graph {
    int g[11][11];
    int ans = 0;

    bool get(int nmb, int x) { return (x & (1 << nmb)) != 0; }

    void gena(int n) {
        for (int i = 1; i < 1 << n; i += 2)
            for (int j = (i == 1) ? 1 : 0; j < n; ++j) {
                t[i][j] = inf;
                if (j > 0 && get(j, i)) {
                    for (int k = 0; k < n; ++k)
                        if (get(k, i) && g[k][j] > 0) t[i][j] = std::min(t[i][j], t[i ^ (1 << j)][k] + g[k][j]);
                }
            }
        ans = inf;
        for (int j = 1; j < n; ++j) {
            if (g[j][0] > 0) {
                ans = std::min(ans, t[(1 << n) - 1][j] + g[j][0]);
            }
        }
    }
};


int main() {
    int n = 0;
    std::cin >> n;
    Graph g;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> g.g[i][j];
        }
    }
    if (n == 1) {
        std::cout << g.g[0][0];
    } else {
        t[1][0] = 0;
        g.gena(n);
        if (g.ans == inf) {
            std::cout << -1;
        } else {
            std::cout << g.ans;
        }
    }
}

