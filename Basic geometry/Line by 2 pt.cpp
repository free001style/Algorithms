#include <iostream>

int main() {
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int A = y2 - y1;
    int B = x1 - x2;
    int C = x2 * y1 - x1 * y2;
    std::cout << A << ' ' << B << ' ' << C;
}
