//Требуется написать программу, которая вычислит, сколько всего
// точек с целочисленными координатами принадлежат отрезку.

#include <iostream>
#include <numeric>

int64_t ab(int64_t a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int64_t a = x1 - x2;
    int64_t b = y1 - y2;
    std::cout << std::gcd(ab(a), ab(b))+1;
    return 0;
}
