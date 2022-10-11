//Напишите программу, которая для двух вершин дерева определяет, является ли одна из них предком другой.

#include <iostream>
#include <vector>

struct Graph {
    std::vector<std::vector<int>> g;
    std::vector<bool> used;
    std::vector<int> in, out;
    int tm = 0;

    Graph(int n) {
        g.resize(n + 1);
        used.resize(n + 1);
        in.resize(n + 1);
        out.resize(n + 1);
    }

    void DFS(int v) {
        used[v] = true;
        in[v] = tm++;
        for (auto now: g[v]) {
            if (!used[now]) {
                DFS(now);
            }
        }
        out[v] = tm++;
    }

    bool par_check(int a, int b) {
        return (in[a] < in[b]) && (out[b] < out[a]);
    }
};


int main() {
    int n = 0, r = 0;
    std::cin >> n;
    Graph g(n);
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        if (tmp == 0) {
            r = i;
        } else {
            g.g[tmp].push_back(i);
        }
    }
    g.DFS(r);
    int query = 0;
    std::cin >> query;
    for (int i = 0; i < query; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << g.par_check(a, b) << std::endl;
    }
}
