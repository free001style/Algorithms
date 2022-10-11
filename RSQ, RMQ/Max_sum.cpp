//В этой задаче вам требуется найти непустой отрезок массива с максимальной суммой.

#include <iostream>
#include <vector>

int main() {
    int N = 0;
    int64_t sum = 0, ans = 0, max = 0;
    std::cin >> N;
    std::vector <int64_t> lst;
    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        lst.push_back(tmp);
    }
    max = lst[0];
    for (int i = 0; i < N; ++i) {
        sum += lst[i];
        if (max < lst[i]) {
            max = lst[i];
        }
        if (sum > ans) {
            ans = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    if (ans == 0) {
        std::cout << max;
    } else
        std::cout << ans;
    return 0;
}
