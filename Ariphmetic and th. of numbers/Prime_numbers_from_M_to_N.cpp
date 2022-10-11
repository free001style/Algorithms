//Вывести все простые числа от M до N включительно.

#include <iostream>
#include <vector>

int main() {
    int64_t n = 0, b = 0, max = 0;
    std::cin >> b >> n;
    std::vector<int64_t> lst;
    int64_t a[n + 1];

    for (int64_t i = 2; i <= n; i++) {
        a[i] = i;
    }
    for (int64_t i = 2; i <= n; i++) {
        if (a[i] != 0) {
            lst.push_back(a[i]);
            max = a[i];
            for (int64_t p = 2 * i; p <= n; p += i) {
                a[p] = 0;
            }
        }
    }
    if (max >= b) {
        for (int64_t i = 0; i < lst.size(); ++i) {
            if (lst[i] >= b) {
                b = i;
                break;
            }
        }
        for (int64_t i = b; i < lst.size(); ++i) {
            std::cout << lst[i] << '\n';
        }
    } else {
        std::cout << "Absent";
    }
    return 0;
}
