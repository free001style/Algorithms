//По данным числам N и K (0 ≤ K ≤ N, 0 ≤ N ≤ 100) выведите все строки
// из нулей и единиц длины N, содержащие ровно K единиц, в лексикографическом порядке.

#include <iostream>
#include <string>


#pragma GCC target ("avx2")
//#pragma GCC optimize("O3")


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::string str;
    for (int i = 0; i < n - k; ++i) {
        str += '0';
    }
    for (int i = 0; i < k; ++i) {
        str += '1';
    }
    do {
        std::cout << str<<'\n';
    } while (std::next_permutation(str.begin(), str.end()));
    return 0;
}

