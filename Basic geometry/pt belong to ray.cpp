#include <iostream>

struct point {
    int x = 0, y = 0;

    point(int x1, int y1) {
        x = x1;
        y = y1;
    }
};

int main() {
    int x = 0, y = 0;
    std::cin >> x >> y;
    point X(x, y);
    std::cin >> x >> y;
    point A(x, y);
    std::cin >> x >> y;
    point B(x, y);
    if ((B.x - A.x) * (X.y - A.y) == (B.y - A.y) * (X.x - A.x) and (X.x - A.x) * (B.x - A.x) >= 0 and
        (X.y - A.y) * (B.y - A.y) >= 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}