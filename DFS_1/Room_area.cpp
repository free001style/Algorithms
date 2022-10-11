//Требуется вычислить площадь комнаты в квадратном лабиринте.

#include <iostream>

class Lab {
public:
    char room[1000][1000];
    size_t S = 0;

    void fun(size_t x, size_t y);
};

void Lab::fun(size_t x, size_t y) {
    if (room[x][y] == '.') {
        S++;
        room[x][y] = '*';
        fun(x - 1, y);
        fun(x + 1, y);
        fun(x, y - 1);
        fun(x, y + 1);
    }
}

int main() {
    Lab lab;
    int n = 0;
    std::cin >> n;
    for (size_t i = 1; i < n + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            std::cin >> lab.room[i][j];
        }
    }
    size_t x = 0, y = 0;
    std::cin >> x >> y;
    lab.fun(x, y);
    std::cout << lab.S;
    return 0;
}
