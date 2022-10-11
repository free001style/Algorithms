//Дан массив из n чисел. Требуется написать программу,
// которая будет отвечать на запросы следующего вида:
// найти минимум на отрезке между u и v включительно.

#include <iostream>
#include <cmath>

#define MAX 100001
#define LOGMAX 17

int a[MAX];
int mas[MAX][LOGMAX];

void check(int &u, int &v) {
    int temp;
    if (u > v) temp = u, u = v, v = temp;
}

void RMQ_nlogn(int n) {
    int i, j;
    for (i = 1; i <= n; i++) mas[i][0] = i;
    for (j = 1; (1 << j) <= n; j++)
        for (i = 1; i + (1 << j) - 1 <= n; i++)
            if (a[mas[i][j - 1]] < a[mas[i + (1 << (j - 1))][j - 1]])
                mas[i][j] = mas[i][j - 1];
            else mas[i][j] = mas[i + (1 << (j - 1))][j - 1];
}

int q(int i, int j) {
    int k = (int) (log(1.0 * j - i + 1) / log(2.0));
    int res = mas[i][k];
    if (a[mas[j - (1 << k) + 1][k]] < a[res])
        res = mas[j - (1 << k) + 1][k];
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N = 0, qu = 0, l, r;
    std::cin >> N >> qu >> a[1];
    std::cin >> l >> r;
    for (int i = 2; i <= N; ++i) {
        a[i] = (23 * a[i - 1] + 21563) % 16714589;
    }
    RMQ_nlogn(N);
    int64_t ans = 0;
    for (int i = 1; i < qu + 1; ++i) {
        int l1, r1;
        l1 = l;
        r1 = r;
        check(l1, r1);
        ans = a[q(l1, r1)];
        if (i < qu) {
            l = ((17 * l + 751 + ans + 2 * i) % N) + 1;
            r = ((13 * r + 593 + ans + 5 * i) % N) + 1;
        }
    }
    std::cout << l << ' ' << r << ' ' << ans;
}
