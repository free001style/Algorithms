#include <iostream>
#include <vector>

#pragma GCC target ("avx2")
#pragma GCC optimize("O3")


struct Graph {
    std::vector<std::vector<int>> left;
    std::vector<int> right;
    std::vector<bool> visited;

    Graph(int L, int R = 0) {
        left.resize(L + 1);
        right.resize(R + 1, -1);
        visited.resize(L + 1, false);
    }

    bool DFS(int v) {
        if (visited[v]) {
            return false;
        }
        visited[v] = true;
        for (auto now: left[v]) {
            if (right[now] == -1 or DFS(right[now])) {
                right[now] = v;
                return true;
            }
        }
        return false;
    }
};

void DFS(size_t vertex, const Graph &graph, std::vector<bool> &visited) {
    visited[vertex] = true;
    for (size_t now: graph.left[vertex]) {
        if (!visited[now])
            DFS(now, graph, visited);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int K = 0;
    std::cin >> K;
    for (int l = 0; l < K; ++l) {
        int L = 0, R = 0;
        std::cin >> L >> R;
        int quan = 0;
        Graph g(L, R);
        for (int i = 1; i < L + 1; ++i) {
            std::vector<int> edges;
            std::vector<bool> invert(R + 1, true);
            int now = 0;
            std::cin >> now;
            while (now != 0) {
                invert[now] = false;
                std::cin >> now;
            }
            for (int j = 1; j < invert.size(); ++j) {
                if (invert[j]) {
                    edges.push_back(j);
                }
            }
            g.left[i] = edges;
            edges.clear();
            invert.clear();
        }
        for (int i = 1; i < g.left.size(); ++i) {
            if (g.DFS(i)) {
                ++quan;
            }
            std::fill(g.visited.begin(), g.visited.end(), 0);
        }
        Graph g1(L + R);
        std::vector<bool> not_dfs(L + 1, true);
        for (int i = 1; i < R + 1; ++i) {
            if (!quan) break;
            if (g.right[i] != -1) {
                g1.left[i + L].push_back(g.right[i]);
                not_dfs[g.right[i]] = false;
                --quan;
            }
        }
        for (int i = 1; i < g.left.size(); ++i) {
            for (int j = 0; j < g.left[i].size(); ++j) {
                if (g.right[g.left[i][j]] != i) {
                    g1.left[i].push_back(L + g.left[i][j]);
                }
            }
        }
        std::vector<bool> visited(L + R + 1, false);
        for (int i = 1; i < L + 1; ++i) {
            if (not_dfs[i] and !visited[i]) {
                DFS(i, g1, visited);
            }
        }
        int ans = 0, boys = 0;
        for (int i = 1; i < visited.size(); ++i) {
            if (i <= L and visited[i]) {
                ++boys;
                ++ans;
            }
            if (i > L and !visited[i]) {
                ++ans;
            }
        }
        std::cout << ans << std::endl;
        std::cout << boys << ' ' << ans - boys << std::endl;
        for (int i = 1; i < visited.size(); ++i) {
            if (i <= L and visited[i]) {
                std::cout << i << ' ';
            }
        }
        std::cout << std::endl;
        for (int i = 1; i < visited.size(); ++i) {
            if (i > L and !visited[i]) {
                std::cout << i - L << ' ';
            }
        }
        std::cout << std::endl;
    }
}
