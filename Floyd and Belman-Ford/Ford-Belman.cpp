//В ориентированном взвешенном графе вершины пронумерованы числами
// от 1 до n. Если i<j, то существует ребро из вершины i в вершину j,
// вес которого определяется по формуле wt(i,j)=(179i+719j) mod 1000 - 500.
// Определите вес кратчайшего пути, ведущего из вершины 1 в вершину n.

#include <vector>
#include <iostream>

int cos(int i, int j) {
    return (179 * i + 719 * j) % 1000 - 500;
}

int main() {
    int INF = 1e9;
    int n = 0;
    std::cin >> n;
    std::vector<int> distance(n + 1, INF);
    distance[1] = 0;
    bool stop = false;
    for (int i = 1; i < n + 1; ++i and stop) {
        stop = true;
        for (int j = i + 1; j < n + 1; ++j) {
            if (distance[i] < INF and distance[j] > distance[i] + cos(i, j)) {
                distance[j] = distance[i] + cos(i, j);
                stop = false;
            }
        }
    }
    std::cout << distance[n];
    return 0;
}
