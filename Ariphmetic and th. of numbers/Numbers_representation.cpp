//Дано натуральное число N. Требуется представить его в виде суммы
// двух натуральных чисел A и B таких, что НОД (наибольший общий делитель)
// чисел A и B — максимален.

#include <iostream>
#include <vector>

#pragma GCC target ("avx2")


bool is_prime(int64_t n) {
    for (int64_t i = 2; i * i < n + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int64_t decomp(int64_t x) {
    bool flag;
    std::vector<int64_t> ans;
    for (int64_t i = 2; i * i <= x; ++i) {
        if (is_prime(i) and x % i == 0) {
            flag = true;
            return i;
        }
    }
    if (!flag) {
        return x;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n = 0;
    std::cin >> n;
    int64_t d = decomp(n);
    if (d == n) {
        std::cout << 1 << ' ' << n - 1;
    } else {
        int64_t m = n / d;
        std::cout << m << ' ' << (d - 1) * m;
    }
    return 0;
}
