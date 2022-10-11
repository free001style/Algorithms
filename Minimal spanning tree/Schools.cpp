//С целью подготовки к проведению олимпиады по информатике мэр решил
// обеспечить надежным электроснабжением все школы города. Для этого
// необходимо провести линию электропередач от альтернативного
// источника электроэнергии “Майбуття” к одной из школ города
// (к какой неважно), а также соединить линиямии электропередач
// некоторые школы между собой. Считается, что школа имеет надежное
// электроснабжение, если она напрямую связана с источником “Майбуття”,
// либо с одной из тех школ, которые имеют надежное электроснабжение.
//Известна стоимость соединения между некоторыми парами школ. Мэр города
// решил выбрать одну из двух наиболее экономичных схем электроснабжения
// (стоимость схемы равняется сумме стоимостей соединений пар школ).
// Напишите программу, которая вычисляет стоимость двух наиболее экономных
// схем альтернативного электроснабжения школ.

#include <iostream>
#include <vector>
#include <cassert>
#include <functional>


struct Edge {
    int a = 0, b = 0, w = 0, type = 0;
};

bool operator<(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int main() {
    int V = 0, E = 0;
    std::cin >> V >> E;
    std::vector <Edge> g;
    for (int i = 0; i < E; ++i) {
        int a = 0, b = 0, w = 0;
        std::cin >> a >> b >> w;
        g.push_back({a, b, w, 1});
    }
    std::vector<int> par(1 + V, -1);
    std::function<int(int)> Root = [&](int ver) {
        if (par[ver] < 0) {
            return ver;
        } else {
            int ret = Root(par[ver]);
            par[ver] = ret;
            return ret;
        }
    };
    std::function<bool(int, int)> Unire = [&](int x, int y) {
        x = Root(x);
        y = Root(y);
        if (x == y) {
            return false;
        }
        assert(par[x] < 0);
        assert(par[y] < 0);
        if (par[x] < par[y]) {
            par[x] += par[y];
            par[y] = x;
        } else {
            par[y] += par[x];
            par[x] = y;
        }
        return true;
    };
    std::sort(g.begin(), g.end());
    int ans1 = 0;
    for (Edge &e: g) {
        if (Unire(e.a, e.b)) {
            ans1 += e.w;
            e.type = 2;
        }
    }
    int ans2 = 10e8;
    for (Edge &e: g) {
        if (e.type == 2) {
            e.type = 3;
            par.assign(1 + V, -1);
            int s = 0;
            int num = 0;
            for (Edge &ee: g) {
                if (ee.type != 3 && Unire(ee.a, ee.b)) {
                    s += ee.w;
                    num++;
                }
            }
            if (num == V - 1) {
                ans2 = std::min(s, ans2);
            }
            e.type = 2;
        }
    }
    std::cout << ans1 << ' ' << ans2;
    return 0;
}
