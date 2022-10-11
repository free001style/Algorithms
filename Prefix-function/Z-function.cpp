#include <iostream>
#include <vector>

std::vector<int> z_func(std::string s) {
    std::vector<int> z(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); ++i) {
        z[i] = std::max(0, std::min(z[i - l], r - i));
        while (i + z[i] < s.size() and s[z[i]] == s[i + z[i]]) {
            ++z[i];
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
    }
    return z;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> p = z_func(s);
    for (auto now: p) {
        std::cout << now << ' ';
    }
}