//Задано подвешенное дерево, содержащее n (1≤n≤100000) вершин,
// пронумерованных от 0 до n-1. Требуется ответить на m (1≤m≤100000)
// запросов о наименьшем общем предке для пары вершин.
//Запросы генерируются следующим образом. Заданы числа a1,a2 и
// числа x, y и z. Числа a3,...,a2m генерируются следующим образом:

#include <iostream>
#include <vector>

int64_t up[100000][18];


struct Graph {
    std::vector<int> g[100000];
    int64_t in[100000], out[100000];
    int64_t tm = 0;
    int64_t s = 1;

    Graph(int64_t n) {
        while ((1 << s) <= n) s++;
    }

    void DFS(int64_t v, int64_t p = 0, int64_t len = 0) {
        in[v] = tm++;
        up[v][0] = p;
        for (int64_t i = 1; i <= s; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (auto now: g[v]) {
            if (now != p) DFS(now, v, len + 1);
        }
        out[v] = tm++;
    }

    bool par_check(int64_t a, int64_t b) {
        return (in[a] <= in[b]) && (out[b] <= out[a]);
    }

    int64_t LCA(int64_t a, int64_t b) {
        if (par_check(b, a)) return b;
        if (par_check(a, b)) return a;
        else {
            for (int64_t i = s; i >= 0; i--)
                if (!par_check(up[a][i], b)) a = up[a][i];
            return up[a][0];
        }
    }
};


int main() {
    int64_t n = 0, m = 0, sz = 1;
    std::cin >> n >> m;
    Graph g(n);
    for (int64_t i = 1; i < n; ++i) {
        int64_t tmp = 0;
        std::cin >> tmp;
        g.g[tmp].push_back(i);
        g.g[i].push_back(tmp);
    }
    g.DFS(0);
    int64_t a = 0, b = 0, x1 = 0, x2 = 0, x3 = 0;
    std::cin >> a >> b >> x1 >> x2 >> x3;
    int64_t ans = 0, pre_ans = 0;
    for (int64_t i = 0; i < m; ++i) {
        pre_ans = g.LCA((a + pre_ans) % n, b);
        ans += pre_ans;
        a = (x1 * a + x2 * b + x3) % n;
        b = (x1 * b + x2 * a + x3) % n;
    }
    std::cout << ans;
}
