//Для того чтобы проверить, как её ученики умеют считать,
// Мария Ивановна каждый год задаёт им на дом одну и ту же
// задачу – для заданного натурального A найти минимальное
// натуральное N такое, что N в степени N (N, умноженное на себя N раз)
// делится на A. От года к году и от ученика к ученику меняется только число A.
//Вы решили помочь будущим поколениям. Для этого вам необходимо написать программу, решающую эту задачу.

#include <iostream>
#include <vector>

#pragma GCC target ("avx2")

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

bool is_prime(int64_t n) {
    for (int64_t i = 2; i * i < n + 1; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<int64_t> decomp(int64_t x) {
    std::vector<int64_t> ans;
    int64_t n = x;
    for (int64_t i = 2; i * i <= x; ++i) {
        if (is_prime(i) and x % i == 0) {
            ans.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        ans.push_back(n);
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n = 0;
    std::cin >> n;
    if (n == 1) {
        std::cout << n;
    } else {
        std::vector<int64_t> d = decomp(n);
        int64_t m = 1;
        for (auto now: d) {
            m *= now;
        }
        if (d[0] != n) {
            for (int64_t i = 0; i < 40; ++i) {
                int64_t tmp = (i + 1) * m;
                if (pow(tmp, tmp, n) == 0) {
                    std::cout << tmp;
                    break;
                }
            }
        } else std::cout << d[0];
    }
    return 0;
}
