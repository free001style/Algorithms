//Найдите перестановку по её номеру в лексикографическом порядке.

#pragma GCC target("avx2")

#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int64_t f(int64_t n) {
    if (n == 0) return 1;
    return f(n - 1) * n;
}

void num(vector<int> a, int64_t k, vector<int> &ans) {
    if (k == 1) {
        for (size_t i = 0; i < a.size(); ++i) {
            ans.push_back(a[i]);
        }
        return;
    }
    int64_t len = a.size() - 1;
    int64_t cnt = f(len);
    int pos = 0;
    while (k > cnt) {
        pos++;
        k -= cnt;
    }
    ans.push_back(a[pos]);
    a.erase(a.begin() + pos);
    num(a, k, ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> a;
    int n = 0, k = 0;
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        a.push_back(i);
    }
    vector<int> ans;
    num(a, k, ans);
    for (auto x: ans) {
        cout << x << ' ';
    }
    return 0;
}
