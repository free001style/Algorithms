#include<iostream>
#include <vector>
#include <limits>

#pragma GCC target ("avx2")
//#pragma GCC optimize("O3")
const double INF = std::numeric_limits<double>::max();

struct Graph {
    double n;
    std::vector <std::vector<double>> ary;
    std::vector<double> completed;
    double cost = 0;

    Graph(double size) {
        n = size;
        ary.resize(n);
        completed.resize(n);
        for (double i = 0; i < n; ++i) {
            ary[i].resize(n);
        }
    }

    double dist(std::pair<double, double> a, std::pair<double, double> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }

    void takeInput() {
        std::vector <std::pair<double, double>> tmp;
        for (double k = 0; k < n; ++k) {
            double a = 0, b = 0;
            std::cin >> a >> b;
            tmp.emplace_back(a, b);
        }
        for (double k = 0; k < n; ++k) {
            for (double l = k + 1; l < n; ++l) {
                ary[k][l] = ary[l][k] = dist(tmp[k], tmp[l]);
            }
            completed[k] = 0;
        }
    }

    double least(double c) {
        double i;
        double nc = INF;
        double min = INF, kmin;

        for (i = 0; i < n; i++) {
            if ((ary[c][i] != 0) && (completed[i] == 0))
                if (ary[c][i] + ary[i][c] < min) {
                    min = ary[i][c] + ary[c][i];
                    kmin = ary[c][i];
                    nc = i;
                }
        }

        if (min != INF)
            cost += kmin;

        return nc;
    }

    void mincost(double city) {
        double i;
        double ncity;

        completed[city] = 1;

        std::cout << city + 1 << ' ';
        ncity = least(city);

        if (ncity == INF) {
            ncity = 0;
            std::cout << ncity + 1 << ' ';
            cost += ary[city][ncity];

            return;
        }
        mincost(ncity);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(0);
    double n = 0;
    std::cin >> n;
    Graph g(n);
    g.takeInput();
    g.mincost(0);
    return 0;
}
