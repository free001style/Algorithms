#include <iostream>
#include <vector>
#include <cmath>


#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

const double EPS = 1e-15;

struct point {
    int x = 0, y = 0;

    point(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }

int operator^(point a, point b) { return a.x * b.y - b.x * a.y; }

bool operator==(point a, point b) { return a.x - b.x < EPS and a.y - b.y < EPS; }


int OrientTriangl2(const point &p1, const point &p2, const point &p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

bool isInside(const point &p1, const point &p, const point &p2) {
    return (p1.x <= p.x && p.x <= p2.x &&
            p1.y <= p.y && p.y <= p2.y);
}

void jarvis(const std::vector<point> &polygon, std::vector<point> &hull) {
    int base = 0;
    for (int i = 1; i < polygon.size(); i++) {
        if (polygon[i].y < polygon[base].y)
            base = i;
        else if (polygon[i].y == polygon[base].y &&
                 polygon[i].x < polygon[base].x)
            base = i;
    }
    hull.push_back(polygon[base]);

    int first = base;
    int cur = base;
    do {
        int next = (cur + 1) % polygon.size();
        for (int i = 0; i < polygon.size(); i++) {
            int sign = OrientTriangl2(polygon[cur], polygon[next], polygon[i]);
            if (sign < 0)
                next = i;
            else if (sign == 0) {
                if (isInside(polygon[cur], polygon[next], polygon[i]))
                    next = i;
            }
        }
        cur = next;
        hull.push_back(polygon[next]);
    } while (cur != first);
}

double perimetr(const std::vector<point> &polygon) {
    double p = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        int j = (i + 1) % polygon.size();
        p += sqrt((polygon[i].x - polygon[j].x) * (polygon[i].x - polygon[j].x) +
                  (polygon[i].y - polygon[j].y) * (polygon[i].y - polygon[j].y));
    }
    return p;
}

double area(const std::vector<point> &polygon) {
    double ans = 0;
    for (int i = 0; i < polygon.size(); ++i) {
        point
                p1 = i ? polygon[i - 1] : polygon.back(),
                p2 = polygon[i];
        ans += (p1.x - p2.x) * (p1.y + p2.y);
    }
    return fabs(ans) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int N = 0;
    std::cin >> N;
    std::vector<point> polygon;
    for (int i = 0; i < N; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        polygon.push_back(point(x, y));
    }
    std::vector<point> shell;
    jarvis(polygon, shell);
    std::cout << perimetr(shell) << std::endl;
    std::cout << area(shell);
}
