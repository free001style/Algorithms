//Полный ориентированный взвешенный граф задан матрицей смежности.
// Постройте матрицу кратчайших путей между его вершинами.
// Гарантируется, что в графе нет циклов отрицательного веса.

#include <vector>
#include <iostream>

int main() {
    int INF = 1e9;
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, INF));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            int tmp = 0;
            std::cin >> tmp;
            graph[i][j] = tmp;
        }
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t from = 0; from < n; ++from) {
            for (size_t to = 0; to < n; ++to) {
                graph[from][to] = std::min(graph[from][i] + graph[i][to], graph[from][to]);

            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
