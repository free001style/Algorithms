//На вход даны числа X, N, P. Требуется вычислить , такое что 0 ≤ y < P

#include <iostream>
#include <cmath>


int64_t pow(int64_t a, int64_t n, int64_t p) {
    if (n == 0)
        return 1 % p;
    if (n % 2 == 1)
        return pow(a, n - 1, p) % p * a % p;
    else {
        int64_t b = pow(a, n / 2, p) % p;
        return (b * b) % p;
    }
}


int main() {
    int64_t x = 0, n = 0, p = 0;
    std::cin >> x >> n >> p;
    std::cout << pow(x, n, p);
    return 0;
}
