//В неориентированном графе требуется найти минимальный путь между двумя вершинами.

#include <iostream>
#include <vector>
#include <queue>

class Graph {


public:
    int num_ver = 0;
    std::vector<std::vector<int>> graph;
    std::vector<int> mark;
    std::vector<bool> used;
    std::vector<std::pair<int, int>> d;

    Graph(int V);

    void addEdge(int src, int dest);

    void DFS(int);

    void BFS(int vertex);
};

Graph::Graph(int vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    mark.resize(vertices + 1);
    d.resize(vertices + 1);
    used.resize(vertices + 1);
}

void Graph::addEdge(int src, int dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(int vertex) {
    used[vertex] = true;
    for (auto now: graph[vertex]) {
        if (!used[now]) {
            DFS(now);
        }
    }
}

void Graph::BFS(int start) {
    std::queue<int> q;
    // Инициализация: есть информация про начальную вершину
    q.push(start);
    d[start] = {0, -1};// first-это расстояние, second- это предок.
    mark[start] = 1;
    // Главный цикл - пока есть серые вершины
    while (!q.empty()) {
        // Берем первую из них
        int v = q.front();
        q.pop();
        // Пробегаемся по всем ее соседям
        for (int i = 0; i < (int) graph[v].size(); ++i) {
            // Если сосед белый
            if (mark[graph[v][i]] == 0) {
                // То вычисляем расстояние
                d[graph[v][i]].second = v;
                d[graph[v][i]].first = d[v].first + 1;
                // И он становится серым
                mark[graph[v][i]] = 1;
                q.push(graph[v][i]);
            }
        }
    }
}


int main() {
    int V = 0, tmp = 0;
    std::cin >> V;
    Graph g(V);
    for (int i = 1; i < V + 1; ++i) {
        for (int j = 1; j < V + 1; ++j) {
            std::cin >> tmp;
            if (tmp == 1) {
                g.addEdge(i, j);

            }
        }
    }
    int start = 0, finish = 0;
    std::cin >> start >> finish;
    g.DFS(start);
    if (g.used[finish]) {
        g.BFS(start);
        if (g.d[finish].first != 0) {
            std::cout << g.d[finish].first << std::endl;
            std::vector<int> ans;
            ans.push_back(finish);
            int cur_v = g.d[finish].second;
            while (cur_v != -1) {
                ans.push_back(cur_v);
                cur_v = g.d[cur_v].second;
            }
            std::reverse(ans.begin(), ans.end());
            for (auto now: ans) {
                std::cout << now << " ";
            }
        } else {
            std::cout << g.d[finish].first;
        }
    } else {
        std::cout << -1;
    }
    return 0;
}
