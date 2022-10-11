//В 3141 году очередная экспедиция на Марс обнаружила в одной из пещер таинственные знаки.
//Теперь ученым срочно нужна программа, которая по заданным числам N и K найдет количество
// нулей в конце записи в системе счисления с основанием K числа

#include <iostream>
#include <vector>
#include <unordered_map>


#pragma GCC target ("avx2")


bool is_prime(int64_t n) {
    for (int64_t i = 2; i * i < n + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//
std::unordered_map<int64_t, int64_t> decomp(int64_t x) {
    std::unordered_map<int64_t, int64_t> ans;
    int64_t n = x;
    for (int64_t i = 2; i * i <= x; ++i) {
        if (is_prime(i) and x % i == 0) {
            while (n % i == 0) {
                ans[i]++;
                n /= i;
            }
        }
    }
    if (n != 1) {
        ans[n] = 1;
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n = 0, k = 0, ans = 1e9;
    std::cin >> n >> k;
    std::unordered_map<int64_t, int64_t> d = decomp(k);
    for (auto now: d) {
        int64_t tmp = now.first, count = 0;
        while (n >= tmp) {
            count += n / tmp;
            tmp *= now.first;
        }
        ans = std::min(ans, count / now.second);
    }
    std::cout << ans;
    return 0;
}
