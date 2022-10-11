#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <map>

void ZLW_compress(const std::string &uncompressed) {
    int DictSize = 128;
    std::map<std::string, int> dict;
    for (int i = 0; i < 128; ++i) {
        dict[std::string(1, i)] = i;
    }
    std::string w;
    std::vector<int> result;
    for (std::string::const_iterator it = uncompressed.begin(); it != uncompressed.end(); ++it) {
        char c = *it;
        std::string wc = w + c;
        if (dict.find(wc) != dict.end()) {
            w = wc;
        } else {
            result.push_back(dict[w]);
            dict[wc] = DictSize++;
            w = std::string(1, c);
        }
    }
    if (!w.empty()) {
        result.push_back(dict[w]);
    }
    std::cout << result.size() << std::endl;
    for (int now: result) {
        std::cout << now << ' ';
    }
}

int main() {
    std::string uncompressed;
    getline(std::cin,uncompressed);
    ZLW_compress(uncompressed);
}
