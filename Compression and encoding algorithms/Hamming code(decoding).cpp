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


void humming_code(const std::string &code) {
    int add_bits = 0;
    while (code.size() >= pow(2, add_bits)) {
        ++add_bits;
    }
    std::vector<int> message(code.size() + 1);//нумерация начинается с 1
    int index_message = 1, index_code = 0, power = 0;
    for (index_message = 1; index_message < message.size(); ++index_message) {
        if (index_message == pow(2, power) and power <= add_bits) {
            message[index_message] = 0;
            ++power;
        } else {
            message[index_message] = code[index_code] - '0';
        }
        ++index_code;
    }
    power = 0;
    for (index_message = 1; index_message < message.size(); ++index_message) {
        if (index_message == pow(2, power) and power <= add_bits) {
            message[index_message] = sum_checking(message.size(), index_message, message);
            ++power;
        }
    }
    int sum = 0;
    power = 0;
    for (int i = 1; i < message.size(); ++i) {
        if (i == pow(2, power) and power <= add_bits) {
            if (code[i - 1] - '0' != message[i]) {
                sum += i;
            }
            ++power;
        }
    }
    power = 0;
    for (int i = 1; i < message.size(); ++i) {
        if (i != pow(2, power) and power <= add_bits) {
            if (i == sum) {
                std::cout << 1 - message[i];
            } else {
                std::cout << message[i];
            }

        } else { ++power; }
    }
}

int main() {
    std::string code;
    std::cin >> code;
    humming_code(code);
}
