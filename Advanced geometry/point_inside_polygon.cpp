#include <iostream>
#include <vector>


//#pragma GCC target ("avx2")
#pragma GCC optimize("O3")

const double EPS = 1e-6;

struct point {
    int x = 0, y = 0;

    point(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

bool check_on_line(const std::vector<point> &polygon, const point &X) {
    for (int i = 0; i < polygon.size(); ++i) {
        int j = (i + 1) % polygon.size();
        point A = polygon[i];
        point B = polygon[j];
        if ((B.x - A.x) * (X.y - A.y) == (B.y - A.y) * (X.x - A.x) and std::max(A.x, B.x) >= X.x and
            std::max(A.y, B.y) >= X.y and std::min(A.y, B.y) <= X.y and std::min(A.x, B.x) <= X.x) {
            return true;
        }
    }
    return false;
}


bool check_inside(const std::vector<point> &polygon, const point &P) {
    bool ans = false;
    for (int i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        if ((((polygon[i].y <= P.y) && (P.y < polygon[j].y)) || ((polygon[j].y <= P.y) && (P.y < polygon[i].y))) &&
            (((polygon[j].y - polygon[i].y) != 0) &&
             (P.x >
              ((polygon[j].x - polygon[i].x) * (P.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x))))
            ans = 1 - ans;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    int N = 0, X = 0, Y = 0;
    std::cin >> N >> X >> Y;
    point P{X, Y};
    std::vector<point> polygon;
    for (int i = 0; i < N; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        if (x == X and y == Y) {
            std::cout << "YES";
            std::exit(0);
        }
        polygon.push_back(point(x, y));
    }

    if (check_inside(polygon, P) or check_on_line(polygon, P)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}
