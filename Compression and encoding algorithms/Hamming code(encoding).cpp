#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int sum_checking(int length, int add_bit_position, const std::vector<int> &ham_code) {
    int bit_sum = 0, step = 0;
    for (int i = add_bit_position; i < length; i = step + add_bit_position) {
        for (step = i; step < i + add_bit_position and step < length; ++step) {
            if (ham_code[step] == 1) {
                ++bit_sum;
            }
        }
    }
    return bit_sum % 2;
}


std::vector<int> humming_code(const std::string &message) {
    int add_bits = 0;
    while (message.size() + add_bits >= pow(2, add_bits)) {
        ++add_bits;
    }
    std::vector<int> code(message.size() + add_bits + 1);//нумерация начинается с 1
    int index_code = 1, index_message = 0, power = 0;
    while (index_code < code.size()) {
        if (index_code == pow(2, power) and power <= add_bits) {
            code[index_code] = 0;
            ++power;
        } else {
            code[index_code] = message[index_message] - '0';
            ++index_message;
        }
        ++index_code;
    }
    power = 0;
    for (index_code = 1; index_code < code.size(); ++index_code) {
        if (index_code == pow(2, power) and power <= add_bits) {
            code[index_code] = sum_checking(code.size(), index_code, code);
            ++power;
        }
    }
    return code;
}

int main() {
    std::string message;
    std::cin >> message;
    std::vector<int> code = humming_code(message);
    for (int i = 1; i < code.size(); ++i) {
        std::cout << code[i];
    }
}
