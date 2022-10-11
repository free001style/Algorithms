//По данному числу N выведите все строки длины N из нулей и единиц в лексикографическом порядке.

#include <iostream>
#include <string>


#pragma GCC target ("avx2")


void print_binary(int n, std::string str = "") {
    if (str.size() == n) {
        std::cout << str << '\n';
        return;
    }
    print_binary(n, str + '0');
    print_binary(n, str + '1');
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    print_binary(n);
    return 0;
}

