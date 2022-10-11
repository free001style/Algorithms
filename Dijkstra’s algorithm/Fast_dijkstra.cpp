//Вам дано описание дорожной сети страны. Ваша задача – найти длину кратчайшего пути между городами А и B.

#include <iostream>
#include <vector>
#include <set>

int main() {

    const int64_t INF = 1e12;

    size_t n, m;
    std::cin >> n >> m;

    std::vector < std::vector < std::pair < int64_t, int64_t>>> graph(n + 1);

    for (size_t i = 1; i <= m; ++i) {
        int64_t v0, v1, cost;
        std::cin >> v0 >> v1 >> cost;
        graph[v0].push_back({v1, cost});
        graph[v1].push_back({v0, cost});
    }
    int64_t start = 0, finish = 0;
    std::cin >> start >> finish;
    std::set <std::pair<int64_t, int64_t>> queue_list;
    std::vector <int64_t> dist(n + 1, INF);
    std::vector <int64_t> parent(n + 1, -1);

    queue_list.insert({0, start});              // first - расстояние, second - вершина

    dist[start] = 0;

    while (!queue_list.empty()) {
        int64_t cur_v = queue_list.begin()->second;
        queue_list.erase(queue_list.begin());

        for (auto node: graph[cur_v]) {
            int64_t to = node.first;
            int64_t curr_cost = node.second;

            if (dist[cur_v] + curr_cost < dist[to]) {
                if (dist[to] != INF) queue_list.erase({dist[to], to});
                dist[to] = dist[cur_v] + curr_cost;
                queue_list.insert({dist[to], to});
                parent[to] = cur_v;
            }
        }
    }
    if (dist[finish] < INF) {
        std::cout << dist[finish];
    } else {
        std::cout << -1;
    }
    return 0;
}
