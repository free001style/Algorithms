//Даны два натуральных числа. Вычислите их наибольший общий делитель при помощи алгоритма Евклида

#include <iostream>
#include <cmath>


int64_t func(int64_t a, int64_t b) {
    if (a == 1 or b == 1) {
        return 1;
    } else if (b == 0) {
        return a;
    } else {
        return func(b, a % b);
    }
}


int main() {
    int64_t a = 0, b = 0;
    std::cin >> a >> b;
    if (b < a) {
        std::swap(a, b);
    }
    std::cout << func(a, b);
    return 0;
}
