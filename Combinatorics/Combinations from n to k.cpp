//По данным числам N и K выведите все возрастающие последовательности
// длины K из чисел 1..N в лексикографическом порядке.

#include <iostream>
#include <vector>


#pragma GCC target ("avx2")
//#pragma GCC optimize("O3")


bool next_comb(std::vector<int> &a, int n) {
    int k = (int) a.size();
    for (int i = k - 1; i >= 0; --i)
        if (a[i] < n - k + i + 1) {
            ++a[i];
            for (int j = i + 1; j < k; ++j)
                a[j] = a[j - 1] + 1;
            return true;
        }
    return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        a[i] = i + 1;
    }
    do {
        for (auto now: a) {
            std::cout << now << ' ';
        }
        std::cout << '\n';
    } while (next_comb(a, n));
    return 0;
}

