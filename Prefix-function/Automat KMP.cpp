#include <iostream>
#include <vector>
#include <string>


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
    size_t size = 0, alph_sz = 0, dif = 0;
    std::string s;
    std::cin >> size >> alph_sz >> dif;
    std::cin >> s;
    s += '#';
    std::vector<int> pr = prefix(s);
    std::vector<std::vector<int>> aut(size, std::vector<int>(alph_sz));
    size_t cur_max = 0;
    for (size_t i = 0; i < size; ++i) {
        for (size_t ch = 0; ch < alph_sz; ++ch) {
            if (i > 0 and (char) ch + 'a' != s[i]) {
                aut[i][ch] = aut[pr[i - 1]][ch];
                cur_max = std::max(cur_max, i - aut[i][ch]);
            } else
                aut[i][ch] = i + ((char) ch + 'a' == s[i]);
        }
    }
    std::cout << cur_max * dif + size;
}
