//Даны несколько точек на плоскости, некоторые из которых соединены отрезками.
// Множество точек называется связанным, если из любой его точки можно перейти
// в любую точку, перемещаясь только по отрезкам (переходить с отрезка на
// отрезок возможно только в точках исходного множества). Можно за определенную
// плату добавлять новые отрезки (стоимость добавления равна длине добавляемого
// отрезка). Требуется за минимальную стоимость сделать данное множество связанным.

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class Graph {
public:
    int v1 = 0, v2 = 0;
    int w = 0;
};

bool operator<(const Graph &a, const Graph &b) {
    return a.w < b.w;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> x_cor(n + 1);
    std::vector<int> y_cor(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> x_cor[i] >> y_cor[i];
    }
    std::vector<int> par(n + 1, -1);

    std::function<int(int)> Root = [&](int ver) {
        if (par[ver] < 0) {
            return ver;
        } else {
            int ret = Root(par[ver]);
            par[ver] = ret;
            return ret;
        }
    };
    std::function<bool(int, int)> Unire = [&](int x, int y) {
        x = Root(x);
        y = Root(y);
        if (x == y) {
            return false;
        }
        assert (par[x] < 0);
        assert (par[y] < 0);
        if (par[x] < par[y]) {
            par[x] += par[y];
            par[y] = x;
        } else {
            par[y] += par[x];
            par[x] = y;
        }
        return true;
    };
    int e = 0;
    std::cin >> e;
    for (int i = 0; i < e; ++i) {
        int tmp1 = 0, tmp2 = 0;
        std::cin >> tmp1 >> tmp2;
        Unire(tmp1, tmp2);
    }
    std::vector<Graph> g;
    for (int i = 1; i < 1 + n; ++i) {
        for (int j = i + 1; j < n + 1; ++j) {
            g.push_back(Graph{i, j, (x_cor[i] - x_cor[j]) * (x_cor[i] - x_cor[j]) +
                                    (y_cor[i] - y_cor[j]) * (y_cor[i] - y_cor[j])});
        }
    }
    double ans = 0;
    std::sort(g.begin(), g.end());
    for (auto now: g) {
        if (Unire(now.v1, now.v2)) {
            ans += std::sqrt(now.w);
        }
    }
    printf("%.5f", ans);
    return 0;
}
