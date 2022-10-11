#include <iostream>
#include <vector>
#include <algorithm>

//#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

int size(std::vector<int> indset) {
    int size = 0;
    for (auto now: indset) {
        if (now)
            ++size;
    }
    return size;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int V = 0, K = 0, E = 0;
    std::cin >> V >> K >> E;
    if (V >= K and !(V == K and E != 0)) {
        if (E == 0) {
            std::cout << "YES";
            std::exit(0);
        }
        std::vector <std::vector<int>> g(V + 1, std::vector<int>(V + 1));
        for (int i = 0; i < E; ++i) {
            int a = 0, b = 0;
            std::cin >> a >> b;
            g[a][b] = 1;
            g[b][a] = 1;
        }
        std::vector<int> degree(V + 1);
        for (int i = 1; i < V + 1; ++i) {
            int sum = 0;
            for (int j = 1; j < V + 1; ++j) {
                if (g[i][j]) {
                    sum++;
                }
            }
            degree[i] = sum;
        }
        std::vector<int> indset;
        for (int i = 1; i < V + 1; ++i) {
            indset.push_back(i);
            for (int j = 1 + i; j < V + 1; ++j) {
                if (g[i][j] == 0) {
                    indset.push_back(j);
                }
            }
            for (int k = 0; k < indset.size(); ++k) {
                if (i != 0) {
                    for (int j = k + 1; j < indset.size(); ++j) {
                        if (j != 0 and g[indset[k]][indset[j]] == 1) {
                            if (degree[indset[k]] >= degree[indset[j]]) {
                                indset[k] = 0;
                            } else {
                                indset[j] = 0;
                            }
                        }

                    }
                }
            }
            if (size(indset) == K) {
                std::cout << "YES";
                std::exit(0);
            }
            indset.clear();
        }
        std::cout << "NO";
        std::exit(0);
    } else {
        std::cout << "NO";
    }
    return 0;
}
