#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

const double EPS = 1e-15;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int n = 0;
    long double ans = 0;
    std::cin >> n;
    std::vector<point> pt;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        point p(x, y);
        pt.push_back(p);
    }
    for (int i = 0; i < n; ++i) {
        point
                p1 = i ? pt[i - 1] : pt.back(),
                p2 = pt[i];
        ans += (p1.x - p2.x) * (p1.y + p2.y);
    }
    std::cout << std::fixed << std::setprecision(5) << fabs(ans) / 2;
}
