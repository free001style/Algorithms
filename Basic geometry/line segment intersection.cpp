#include <iostream>
#include <cmath>


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
        return x < p.x - EPS || fabs(x - p.x) < EPS && y < p.y - EPS;
    }
};

struct line {
    double A, B, C;

    line(point X, point Y) {
        A = X.y - Y.y;
        B = Y.x - X.x;
        C = -A * X.x - B * X.y;
        double dist = sqrt(A * A + B * B);
        if (fabs(dist) > EPS) {
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
    bool searchig(double l, double r, double x) {
        return std::min(l, r) <= x + EPS && x <= std::max(l, r) + EPS;
    }

    bool intersect(point A, point B, point C, point D, point &one, point &two) {
        if (!bounding(A.x, B.x, C.x, D.x) or !bounding(A.y, B.y, C.y, D.y)) {
            return false;
        }
        line l1(A, B);
        line l2(C, D);
        double det = l1.A * l2.B - l2.A * l1.B;
        if (fabs(det) < EPS) {
            if (fabs(l1.distance(C)) > EPS || fabs(l2.distance(A)) > EPS) {
                return false;
            }
            if (B < A) {
                std::swap(A, B);
            }
            if (D < C) {
                std::swap(D, C);
            }
            one = std::max(A, C);
            two = std::min(B, D);
            return true;
        } else {
            one.x = (-l1.C * l2.B + l2.C * l1.B) / det;
            two.x = (-l1.C * l2.B + l2.C * l1.B) / det;
            one.y = (-l1.A * l2.C + l2.A * l1.C) / det;
            two.y = (-l1.A * l2.C + l2.A * l1.C) / det;
            return searchig(A.x, B.x, one.x) and searchig(A.y, B.y, one.y) and searchig(C.x, D.x, two.x) and
                   searchig(C.y, D.y, two.y);
        }
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
    point one(0, 0);
    point two(1, 1);
    Geometry g;
    if (g.intersect(A, B, C, D, one, two)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
