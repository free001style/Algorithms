//Взвешенный неориентированный граф без петель задан матрицей смежности.
// Распределите вершины по двум долям так, чтобы сумма весов рёбер,
// соединяющих вершины из разных долей, была максимальна.

#include <iostream>
#include <bitset>

int main() {
    int lst[35][35];
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp = 0;
            std::cin >> tmp;
            lst[i][j] = tmp;
        }
    }
    std::bitset<35> ans = 0;
    int max = 0;
    for (int i = 0; i < (1 << n); ++i) {
        std::bitset<35> b = i;
        int s = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (b[j] != b[k]) {
                    s += lst[j][k];
                }
            }
        }
        if (max < s) {
            max = s;
            ans = b;
        }
    }
    std::cout << max << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << ' ';
    }
    return 0;
}
