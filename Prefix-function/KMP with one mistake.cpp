#include <iostream>
#include <vector>
#include <string>


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
    std::string pt, t;
    std::cin >> pt >> t;
    std::vector<int> p = z_func(pt + '#' + t);
    std::vector<int> p_c(p.size() - 1 - pt.size());
    for (int i = pt.size() + 1; i < p.size(); ++i) {
        p_c[i - pt.size() - 1] = p[i];
    }
    p.clear();
    std::reverse(pt.begin(), pt.end());
    std::reverse(t.begin(), t.end());
    std::vector<int> p1 = z_func(pt + '#' + t);
    std::reverse(p1.begin(), p1.end());
    std::vector<int> p1_c(p1.size() - 1 - pt.size());
    for (int i = 0; i < p1.size() - 1 - pt.size(); ++i) {
        p1_c[i] = p1[i];
    }
    p1.clear();
    size_t count = 0;
    for (int i = 0; i < p_c.size(); ++i) {
        if (p_c[i] == pt.size()) {
            ++count;
        } else {
            if (i + pt.size() - 1 < p_c.size() and p_c[i] + p1_c[i + pt.size() - 1] == pt.size() - 1) {
                ++count;
            }
        }
    }
    std::cout << count << std::endl;
    for (int i = 0; i < p_c.size(); ++i) {
        if (p_c[i] == pt.size()) {
            std::cout << i + 1 << ' ';
        } else {
            if (i + pt.size() - 1 < p_c.size() and p_c[i] + p1_c[i + pt.size() - 1] == pt.size() - 1) {
                std::cout << i + 1 << ' ';
            }
        }
    }
}
