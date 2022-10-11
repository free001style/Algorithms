//Дан целочисленный массив A, состоящий из N элементов.
//Обработайте Q запросов следующего вида:
//1 L R — определить сумму элементов с индексами от L до R включительно;
//2 I X — присвоить элементу с индексом I значение X.

#include<iostream>
#include<vector>
#include<algorithm>


const int inf = 2e9;

struct tree {
    int n;
    std::vector<int64_t> t;
    std::vector<int64_t> a;


    tree(int val, std::vector<int64_t> &arr) {
        n = val;
        t.resize(4 * n);
        a.resize(n);
        a = arr;
    }

    void build(int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int64_t sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, std::min(r, tm))
               + sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    int64_t sum(int ql, int qr) {
        return sum(1, 0, n - 1, ql, qr);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = new_val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void update(int pos, int new_val) {
        update(1, 0, n - 1, pos, new_val);
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int64_t> arr;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    tree t(n, arr);
    t.build(1, 0, n - 1);
    int m = 0, type = 0, v1 = 0, v2 = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::cin >> type >> v1 >> v2;
        if (type == 1) {
            std::cout << t.sum(v1, v2) << std::endl;
        }
        if (type == 2) {
            t.update(v1, v2);
        }
    }
    return 0;
}
