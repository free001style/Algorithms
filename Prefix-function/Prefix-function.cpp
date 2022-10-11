#include <iostream>
#include <vector>

std::vector<int> prefix(std::string s) {
    std::vector<int> p(s.size(), 0);
    for (int i = 1; i < s.size(); ++i) {
        int k = p[i - 1];
        while (k > 0 and s[k] != s[i]) {
            k = p[k - 1];
        }
        if (s[k] == s[i]) {
            k++;
        }
        p[i] = k;
    }
    return p;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> p = prefix(s);
    for (auto now: p) {
        std::cout << now << ' ';
    }
}
