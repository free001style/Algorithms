//Дан целочисленный массив A, состоящий из N элементов.
//Обработайте Q запросов следующего вида:
//L R — определить сумму элементов с индексами от L до R включительно.
//Так как количество запросов в этой задаче велико, их аргументы не будут
// описаны во входных данных. Вместо этого вам нужно получить их при
// помощи генератора случайных чисел.
//Вам нужно сгенерировать последовательность чисел X0, X1, ..., X2Q - 1.
// Число X0 указано во входных данных, а остальные числа вычисляются по
// формуле Xi = (11173 ⋅ Xi - 1 + 1) mod 1000000007.
//Далее из этих чисел образуются аргументы запросов:
//L0 = min(X0 mod N, X1 mod N), R0 = max(X0 mod N, X1 mod N);
//L1 = min(X2 mod N, X3 mod N), R1 = max(X2 mod N, X3 mod N);
//...
//LQ - 1 = min(X2Q - 2 mod N, X2Q - 1 mod N), RQ - 1 = max(X2Q - 2 mod N, X2Q - 1 mod N).

#include <iostream>
#include <vector>

int main() {
    int N = 0;
    std::cin >> N;
    std::vector<int64_t> lst;
    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        lst.push_back(tmp);
    }
    std::vector<int64_t> pr_sum(N + 1);
    pr_sum[1] = lst[0];
    for (int i = 2; i < N + 1; ++i) {
        pr_sum[i] = pr_sum[i - 1] + lst[i - 1];
    }
    int que = 0, st;
    int64_t ans = 0;
    std::cin >> que >> st;

    std::vector<int64_t> bounds(2 * que);
    bounds[0] = st;
    for (int i = 1; i <= bounds.size(); ++i) {
        bounds[i] = (11173 * bounds[i - 1] + 1) % 1000000007;
    }

    for (int i = 1; i <= que; ++i) {
        int L = 0, R = 0;
        L = std::min(bounds[2 * i - 1] % N, bounds[2 * i - 2] % N);
        R = std::max(bounds[2 * i - 1] % N, bounds[2 * i - 2] % N);
        ans += (pr_sum[R + 1] -
                pr_sum[L])% 1000000007;
    }
    std::cout << ans % 1000000007;
}

