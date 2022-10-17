#include <tuple>
#include <cmath>
#include<iostream>
#include<vector>
#include <unordered_set>
#include <iomanip>

#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

struct point {
    double x = 0, y = 0;

    point(double x1, double y1) {
        x = x1;
        y = y1;
    }
};


point operator*(point a, point b) { return point{a.x * b.x, a.y * b.y}; }

point operator/(point a, point b) { return point{a.x / b.x, a.y / b.y}; }

point operator+(point a, point b) { return point{a.x + b.x, a.y + b.y}; }

point operator-(point a, point b) { return point{a.x - b.x, a.y - b.y}; }

double operator^(point a, point b) { return a.x * b.y - b.x * a.y; }


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    double X = 0, Y = 0;
    std::cin >> X >> Y;
    double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    std::cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
    point a(a1, a2), b(b1, b2), c(c1, c2), d(d1, d2);
    point v1(b.x - a.x - X, b.y - a.y);
    point v2(d.x - a.x, d.y - a.y - Y);
    std::cout << std::fixed << std::setprecision(3) << ((v2 ^ a) / (v1 ^ v2)) * X
              << ' '
              << ((a ^ v1) / (v1 ^ v2)) * Y;
    return 0;
}
