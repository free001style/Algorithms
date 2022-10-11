#include <iostream>
#include <vector>
#include <queue>

#pragma GCC target ("avx2")
//#pragma GCC optimize("O3")
#pragma GCC optimization ("unroll-loops")

const int INF = 1e9;
struct Edge {
    int from, to, cost, flow;
};

struct Graph {
    std::vector<std::vector<int>> graph;
    std::vector<Edge> edges;
    std::vector<int> d, p, path_masha, path_petya;
    std::queue<int> q;
    std::vector<bool> visited;
    int s = 0, t = 0;

    Graph(int V, int st, int tar, int E) {
        graph.resize(V);
        d.resize(V);
        p.resize(V);
        s = st;
        t = tar;
        visited.assign(2 * E, false);
    }

    int DFS(int u, int flow) {
        if (u == t or flow == 0) {
            return flow;
        }
        for (; p[u] < graph[u].size(); ++p[u]) {
            int id = graph[u][p[u]];
            int v = edges[id].to;
            if (d[v] == d[u] + 1) {
                int push = DFS(v, std::min(flow, edges[id].cost - edges[id].flow));
                if (push) {
                    edges[id].flow += push;
                    edges[id ^ 1].flow -= push;
                    return push;
                }
            }
        }
        return 0;
    }

    bool BFS() {
        d.assign(graph.size(), INF);
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); ++i) {
                int id = graph[u][i];
                int v = edges[id].to;

                if (edges[id].flow < edges[id].cost and d[v] == INF) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != INF;
    }

    void dfs_for_path_masha(int u) {
        path_masha.push_back(u);

        if (u == t) {
            return;
        }

        for (int id: graph[u]) {
            int v = edges[id].to;

            if (!visited[id] and edges[id].flow == 1) {
                visited[id] = true;
                dfs_for_path_masha(v);
                break;
            }
        }
    }

    void dfs_for_path_petya(int u) {
        path_petya.push_back(u);

        if (u == t) {
            return;
        }

        for (int id: graph[u]) {
            int v = edges[id].to;

            if (!visited[id] and edges[id].flow == 1) {
                visited[id] = true;
                dfs_for_path_petya(v);
                break;
            }
        }
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int V, E;
    std::cin >> V >> E;
    int a = 0, h = 0;
    std::cin >> a >> h;
    a--;
    h--;
    Graph g(V, a, h, E);
    for (int i = 0; i < E; ++i) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        from--;
        to--;
        g.graph[from].push_back(g.edges.size());
        g.edges.push_back({from, to, 1, 0});
        g.graph[to].push_back(g.edges.size());
        g.edges.push_back({to, from, 0, 0});
    }
    int flow = 0;
    while (g.BFS()) {
        g.p.assign(V, 0);
        while (int f = g.DFS(g.s, INF)) {
            flow += f;
        }
    }
    if (flow > 1) {
        std::cout << "YES" << std::endl;
        g.dfs_for_path_masha(g.s);
        g.dfs_for_path_petya(g.s);
        for (auto now: g.path_masha) {
            std::cout << now + 1 << ' ';
        }
        std::cout << std::endl;

        for (auto now: g.path_petya) {
            std::cout << now + 1 << ' ';
        }
    } else {
        std::cout << "NO";
    }
    return 0;
}
