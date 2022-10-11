//Профессор Флойд живёт в очень опасном районе города.
// Ежедневно бандиты грабят на улицах прохожих.
// Читая криминальную хронику, профессор Флойд
// вычислил вероятность быть ограбленным при проходе
// по каждой улице города. Теперь он хочет найти
// наиболее безопасный путь от дома до университета,
// в котором он преподаёт. Иными словами,
// он хочет найти путь от дома до университета,
// для которого вероятность быть ограбленным минимальна.

#include <vector>
#include <iostream>

int main() {
    int INF = 1e9;
    int n = 0, m = 0, st = 0, fin = 0;
    std::cin >> n >> m >> st >> fin;
    st--;
    fin--;
    std::vector<std::vector<double>> graph(n, std::vector<double>(n, 1));
    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0;
        double c = 0;
        std::cin >> a >> b >> c;
        a--;
        b--;
        graph[a][b] = c / 100;
        graph[b][a] = c / 100;
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t from = 0; from < n; ++from) {
            for (size_t to = 0; to < n; ++to) {
                graph[from][to] = std::min(graph[from][i] + graph[i][to] - (graph[from][i] * graph[i][to]),
                                           graph[from][to]);

            }
        }
    }
    std::cout << graph[st][fin];
    return 0;
}
