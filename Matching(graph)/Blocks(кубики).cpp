#include <iostream>
#include <vector>

struct Graph {
    std::vector <std::vector<int>> left;
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
    int n = 0;
    std::cin >> n;
    std::string name;
    std::cin >> name;
    std::vector <std::vector<char>> dict(n + 1);
    Graph g(n, name.size());
    for (int i = 1; i < n + 1; ++i) {
        std::vector<bool> flag(name.size(), 1);
        std::vector<char> cub;
        std::vector<int> edges;
        for (int j = 0; j < 6; ++j) {
            char s;
            std::cin >> s;
            for (int k = 0; k < name.size(); ++k) {
                if (s == name[k] and flag[k]) {
                    edges.push_back(k + 1);
                    flag[k] = 0;
                }
            }
            cub.push_back(s);
        }
        dict[i] = cub;
        cub.clear();
        g.left[i] = edges;
        edges.clear();
        std::fill(flag.begin(), flag.end(), 1);
    }
    int quan = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (g.DFS(i)) {
            ++quan;
        }
        std::fill(g.visited.begin(), g.visited.end(), 0);
    }
    if (quan == name.size()) {
        std::cout << "YES" << std::endl;
        for (int i = 1; i < g.right.size(); ++i) {
            std::cout << g.right[i] << ' ';
        }
    } else {
        std::cout << "NO";
    }
}
