//В государстве алхимиков есть N населённых пунктов, пронумерованных числами
// от 1 до N, и M дорог. Населённые пункты бывают двух типов: деревни и города.
// Кроме того, в государстве есть одна столица (она может располагаться как в
// городе, так и в деревне). Каждая дорога соединяет два населённых пункта, и для
// проезда по ней требуется Ti минут. В столице было решено провести 1-ю
// государственную командную олимпиаду по алхимии. Для этого во все города из
// столицы были отправлены гонцы (по одному гонцу на город) с информацией про олимпиаду.
//Напишите программу, которая посчитает, в каком порядке и через какое время каждый
// из гонцов доберётся до своего города. Считается, что гонец во время пути не
// спит и нигде не задерживается.

#include <iostream>
#include <vector>
#include <set>

int main() {

    const int64_t INF = 1e12;

    int64_t n = 0, m = 0, city = 0, start = 0;
    std::cin >> n >> m >> city >> start;
    std::vector <int64_t> cities;
    for (int i = 0; i < city; ++i) {
        int64_t c = 0;
        std::cin >> c;
        cities.push_back(c);
    }

    std::vector < std::vector < std::pair < int64_t, int64_t>>> graph(n + 1);

    for (size_t i = 1; i <= m; ++i) {
        int64_t v0, v1, cost;
        std::cin >> v0 >> v1 >> cost;
        graph[v0].push_back({v1, cost});
        graph[v1].push_back({v0, cost});
    }
    std::set <std::pair<int64_t, int64_t>> queue_list;
    std::vector <int64_t> dist(n + 1, INF);

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
            }
        }
    }
    std::vector <std::pair<int64_t, int64_t>> ans;
    for (size_t i = 0; i < dist.size(); ++i) {
        ans.push_back({dist[i], i});
    }
    sort(ans.begin(), ans.end());
    for (auto [dis, node]: ans) {
        if (find(cities.begin(), cities.end(), node) != cities.end()) {
            std::cout << node << " " << dis << std::endl;
        }
    }
    return 0;
}
