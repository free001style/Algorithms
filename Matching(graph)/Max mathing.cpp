#include <iostream>
#include <vector>

struct Graph {
    std::vector<std::vector<int>> left;
    std::vector<int> right;
    std::vector<bool> visited;

    Graph(int L, int R) {
        left.resize(L + 1);
        right.resize(R + 1, -1);
        visited.resize(L + 1, 0);
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

int main() {
    int L = 0, R = 0;
    std::cin >> L >> R;
    int quan = 0;
    Graph g(L, R);
    for (int i = 1; i < L + 1; ++i) {
        std::vector<int> edges;
        int now = 0;
        std::cin >> now;
        while (now != 0) {
            edges.push_back(now);
            std::cin >> now;
        }
        g.left[i] = edges;
        edges.clear();
    }

    for (int i = 1; i < L + 1; ++i) {
        if (g.DFS(i)) {
            ++quan;
        }
        std::fill(g.visited.begin(), g.visited.end(), 0);
    }
    std::cout << quan << std::endl;
    for (int i = 1; i < R + 1; ++i) {
        if (g.right[i] != -1) {
            std::cout << g.right[i] << ' ' << i << std::endl;
        }
    }
}
