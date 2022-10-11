//Выведите все простые делители данного числа с учётом кратности.

#include <iostream>
#include <vector>
#include <cmath>


bool is_prime(int64_t n) {
    for (int64_t i = 2; i * i < n + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void print(int64_t &a, int64_t i) {
    while (a % i == 0) {
        std::cout << i << ' ';
        a /= i;
    }
}

int main() {
    int64_t a = 0;
    std::cin >> a;
    for (int64_t i = 2; i * i <= a; ++i) {
        if (is_prime(i) and a % i == 0) {
            print(a, i);
        }
    }
    if (a != 1) {
        std::cout << a;
    }
    return 0;
}


