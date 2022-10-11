#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>

void ZLW_decompress(const std::vector<int> &code) {
    int DictSize = 128;
    std::map<int, std::string> dict;
    for (int i = 0; i < 128; ++i) {
        dict[i] = std::string(1, i);
    }
    std::string w(1, code[0]);
    std::string result = w, stream;
    for (int i = 1; i < code.size(); ++i) {
        if (dict.find(code[i]) != dict.end()) {
            stream = dict[code[i]];
        } else if (code[i] == DictSize) {
            stream = w + w[0];
        }
        result += stream;
        dict[DictSize++] = w + stream[0];
        w = stream;
    }
    std::cout << result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> code(n);
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        code[i] = tmp;
    }
    ZLW_decompress(code);
}
