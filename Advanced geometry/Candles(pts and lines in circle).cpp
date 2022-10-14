#include <tuple>
#include <cmath>
#include<iostream>
#include<vector>
#include <unordered_set>

const double EPS = 1e-6;


struct point {
    double x = 0, y = 0;

    point(double x1, double y1) {
        x = x1;
        y = y1;
    }
};

double operator^(point a, point b) { return a.x * b.y - a.y * b.x; }

std::pair<point, point> circle_line(double r, double a, double b, double c) {
    double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
    if (c * c <= r * r * (a * a + b * b) + EPS and fabs(c * c - r * r * (a * a + b * b)) >= EPS) {
        double d = r * r - c * c / (a * a + b * b);
        double mult = sqrt(d / (a * a + b * b));
        return {point{x0 + b * mult, y0 - a * mult}, point{x0 - b * mult, y0 + a * mult}};
    }
}

bool is_left(point C, point A, point B) {
    point x{B.x - A.x, B.y - A.y};
    point y{C.x - A.x, C.y - A.y};
    return (y ^ x) > 0;
}


int main() {
    int N = 0, M = 0, R = 0;
    std::cin >> N >> M >> R;
    std::vector<point> candles;
    for (int i = 0; i < N; ++i) {
        double x = 0, y = 0;
        std::cin >> x >> y;
        candles.push_back(point{x, y});
    }
    std::vector<std::string> check(N, "");
    for (int i = 0; i < M; ++i) {
        double a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;
        for (int j = 0; j < N; ++j) {
            std::pair<point, point> tmp = circle_line(R, a, b, c);
            if (is_left(candles[j], tmp.first, tmp.second)) {
                check[j] += "1";
            } else {
                check[j] += "0";
            }
        }
    }
    std::unordered_set<std::string> v(check.begin(), check.end());
    if (v.size() != check.size()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
