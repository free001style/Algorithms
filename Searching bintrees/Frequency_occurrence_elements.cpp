//По данной последовательности постройте дерево,
// запоминая для каждого элемента его значение и
// количество его повторений в последовательности.

#include<iostream>
#include<map>

int main() {
    int tmp = 0;
    std::cin >> tmp;
    std::map<int, int> ans;
    while (tmp != 0) {
        ans[tmp]++;
        std::cin >> tmp;
    }
    for (auto now: ans) {
        std::cout << now.first << ' ' << now.second << std::endl;
    }
}
