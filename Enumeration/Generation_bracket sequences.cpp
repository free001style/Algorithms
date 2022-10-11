//По данному числу n выведите все правильные скобочные последовательности из круглых и
// квадратных скобок длины n в лексикографическом порядке.

#include<iostream>
#include<vector>



void gena(std::string a, int open1, int close1, int open2, int close2, int len,std::vector<std::string> br, std::string now = "") {
    if (close1 > open1 or close2 > open2) return;
    if (2 * open1 + 2 * open2 > len) return;

    if (br.size() != 0) {
        if ((br.back() == "[" and now == ")") or (br.back() == "(" and now == "]")) {
            return;
        }
        if ((br.back() == "[" and now == "]") or (br.back() == "(" and now == ")")) {
            br.pop_back();

        }

    }

    if (now != "]" and now != ")" and !now.empty()) {
        br.push_back(now);
    }

    if (open1 + close1 + open2 + close2 == len) {
        std::cout << a << '\n';
        return;
    }
    gena(a + "(", open1 + 1, close1, open2, close2, len,br, "(");
    gena(a + "[", open1, close1, open2 + 1, close2, len,br, "[");
    gena(a + "]", open1, close1, open2, close2 + 1, len,br, "]");
    gena(a + ")", open1, close1 + 1, open2, close2, len,br, ")");
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::string> br;
    gena("", 0, 0, 0, 0, n,br);

    return 0;
}