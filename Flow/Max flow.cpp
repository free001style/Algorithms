#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#pragma GCC target ("avx2")

const long long INF = std::numeric_limits<long long>::max();
struct Edge {
    long long from, to, cost, flow;
};

struct Graph {
    std::vector<std::vector<long long>> graph;
    std::vector<Edge> edges;
    std::vector<long long> d, p;
    std::queue<long long> q;
    long long s = 0, t = 0;

    Graph(long long V) {
        graph.resize(V);
        d.resize(V);
        p.resize(V);
        t = V - 1;
    }

    long long dfs(long long u, long long flow) {
        if (u == t or flow == 0) {
            return flow;
        }
        for (; p[u] < graph[u].size(); ++p[u]) {
            long long id = graph[u][p[u]];
            long long v = edges[id].to;
            if (d[v] == d[u] + 1) {
                long long push = dfs(v, std::min(flow, edges[id].cost - edges[id].flow));
                if (push) {
                    edges[id].flow += push;
                    edges[id ^ 1].flow -= push;
                    return push;
                }
            }
        }
        return 0;
    }

    bool bfs() {
        d.assign(graph.size(), INF);
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            long long u = q.front();
            q.pop();
            for (long long i = 0; i < graph[u].size(); ++i) {
                long long id = graph[u][i];
                long long v = edges[id].to;

                if (d[v] == INF and edges[id].flow < edges[id].cost) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != INF;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    long long V, E;
    std::cin >> V >> E;
    Graph g(V);

    for (long long i = 0; i < E; ++i) {
        long long ai, bi, ci;
        std::cin >> ai >> bi >> ci;
        ai--;
        bi--;

        g.graph[ai].push_back(g.edges.size());
        g.edges.push_back({ai, bi, ci, 0});
        g.graph[bi].push_back(g.edges.size());
        g.edges.push_back({bi, ai, 0, 0});
    }

    long long flow = 0;
    while (g.bfs()) {
        g.p.assign(V, 0);
        while (long long f = g.dfs(g.s, INF)) {
            flow += f;
        }
    }
    std::cout << flow;
    return 0;
}
