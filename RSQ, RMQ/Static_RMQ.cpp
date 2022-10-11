//Дан целочисленный массив A, состоящий из N элементов.
//Обработайте Q запросов следующего вида:
//L R — определить минимальный из элементов с индексами от L до R включительно.

#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N = 0;
    std::cin >> N;
    int log[N+1];
    int st[18][N];
    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        st[0][i] = tmp;
    }
    log[1] = 0;
    for (int i = 2; i <= N; i++) {
        log[i] = log[i / 2] + 1;
    }
    for (int i = 1; i < log[N]+1; ++i) {
        for (int j = 0; j + (1 << i) < N+1; ++j) {
            st[i][j] = std::min(st[i - 1][j], st[i - 1][j + ((1 << i) / 2)]);
        }
    }
    int qu=0;
    std::cin>>qu;
    int64_t sum=0;
    for (int j = 0; j < qu; ++j) {
        int l=0,r=0;
        std::cin>>l>>r;
        int64_t i=1<<log[r-l+1];
        sum+=std::min(st[log[r-l+1]][l],st[log[r-l+1]][r-i+1]);
    }
    std::cout << sum;
}
