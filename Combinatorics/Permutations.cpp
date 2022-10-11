//По данному числу N (0<N<10) выведите все перестановки чисел от 1 до N в лексикографическом порядке.

#include <iostream>
#include <algorithm>
#include <vector>

void print_permutations(int64_t n) {
    std::vector<size_t> ans;
    for (int i = 1; i <= n; ++i) {
        ans.push_back(i);
    }
    do {
        for (auto now: ans) {
            std::cout << now;
        }
        std::cout << '\n';
    } while (std::next_permutation(ans.begin(), ans.end()));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n = 0;
    std::cin >> n;
    print_permutations(n);
}

