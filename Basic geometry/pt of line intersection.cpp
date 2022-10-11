#include <iostream>
#include <cmath>
#include <iomanip>


#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

const double EPS = 1e-15;

struct point {
    double x = 0, y = 0;

    point(double x1, double y1) {
        x = x1;
        y = y1;
    }

    bool operator<(const point &p) const {
        return x < p.x - EPS || abs(x - p.x) < EPS && y < p.y - EPS;
    }

    bool operator==(const point &p) const {
        return x == p.x and y == p.y;
    }
};

struct line {
    double A, B, C;

    line(point X, point Y) {
        A = X.y - Y.y;
        B = Y.x - X.x;
        C = -A * X.x - B * X.y;
        double dist = sqrt(A * A + B * B);
        if (abs(dist) > EPS) {
            A /= dist;
            B /= dist;
            C /= dist;
        }

    }

    double distance(point p) {
        return A * p.x + B * p.y + C;
    }
};

struct Geometry {
    bool intersect(line l1, line l2, point &ans) {
        double det = l1.A * l2.B - l2.A * l1.B;
        if (fabs(det) < EPS) {
            return false;
        }
        ans.x = (-l1.C * l2.B + l2.C * l1.B) / det;
        ans.y = (-l1.A * l2.C + l2.A * l1.C) / det;
        return true;
    }

    bool parallel(line l1, line l2) {
        return fabs(l1.A * l2.B - l1.B * l2.A) < EPS;
    }

    bool equivalent(line l1, line l2) {
        return fabs(l1.A * l2.B - l1.B * l2.A) < EPS
               and fabs(l1.A * l2.C - l1.C * l2.A) < EPS
               and fabs(l1.B * l2.C - l1.C * l2.B) < EPS;
    }

};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    double x = 0, y = 0;
    std::cin >> x >> y;
    point A(x, y);
    std::cin >> x >> y;
    point B(x, y);
    std::cin >> x >> y;
    point C(x, y);
    std::cin >> x >> y;
    point D(x, y);
    point ans(0, 0);
    line l1(A, B);
    line l2(C, D);
    Geometry g;
    if (g.equivalent(l1, l2)) {
        std::cout << 2;
    } else if (g.parallel(l1, l2)) {
        std::cout << 0;
    } else {
        g.intersect(l1, l2, ans);
        if (ans.x == -0) ans.x = fabs(ans.x);
        if (ans.y == -0) ans.y = fabs(ans.y);
        std::cout << 1 << ' ' << std::fixed << std::setprecision(2) << ans.x << ' ' << ans.y;
    }
}
