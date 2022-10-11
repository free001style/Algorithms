//Дан ориентированный граф. Определить, есть ли в нем
// цикл отрицательного веса, и если да, то вывести его.

#include <queue>
#include <vector>
#include <iostream>

struct edge {
    int a, b, cost;
};

int main() {
    int INF = 1e9;
    int n = 0;
    std::cin >> n;
    std::vector<edge> e;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp = 0;
            std::cin >> tmp;
            if (tmp != 100000) {
                e.push_back({i, j, tmp});
            }
        }
    }
    std::vector<int> d(n, INF);
    d[0] = 0;
    std::vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &j: e)
            if (d[j.a] < INF)
                if (d[j.b] > d[j.a] + j.cost) {
                    d[j.b] = std::max(-INF, d[j.a] + j.cost);
                    p[j.b] = j.a;
                    x = j.b;
                }
    }

    if (x == -1)
        std::cout << "NO";
    else {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        std::vector<int> ans;
        for (int i = y;; i = p[i]) {
            ans.push_back(i);
            if (i == y && ans.size() > 1) break;
        }
        reverse(ans.begin(), ans.end());

        std::cout << "YES" << std::endl;
        std::cout << ans.size() << std::endl;
        for (int i: ans)
            std::cout << i + 1 << ' ';
    }
    return 0;
}
