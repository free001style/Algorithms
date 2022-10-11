//Предприятие «Авто-2010» выпускает двигатели для известных
// во всём мире автомобилей. Двигатель состоит ровно из n
// деталей, пронумерованных от 1 до n, при этом деталь с
// номером i изготавливается за pi секунд. Специфика предприятия
// «Авто-2010» заключается в том, что там одновременно может
// изготавливаться лишь одна деталь двигателя. Для производства
// некоторых деталей необходимо иметь предварительно изготовленный
// набор других деталей. Генеральный директор «Авто-2010» поставил
// перед предприятием амбициозную задачу — за наименьшее время
// изготовить деталь с номером 1, чтобы представить её на выставке.
// Требуется написать программу, которая по заданным зависимостям
// порядка производства между деталями найдёт наименьшее время,
// за которое можно произвести деталь с номером 1.

#include <iostream>
#include <vector>

void dfs(size_t now, const std::vector<std::vector<size_t>>& graph, const std::vector<size_t> &times, std::vector<bool> &used,
         std::vector<size_t> &order, size_t &min_time) {
    if (used[now]) return;
    for (auto neig: graph[now]) {
        dfs(neig, graph, times, used, order, min_time);
    }
    order.push_back(now);
    min_time += times[now];
    used[now] = true;
}

int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<size_t> times(n + 1);
    for (size_t i = 1; i < n + 1; ++i) {
        size_t time = 0;
        std::cin >> time;
        times[i] = time;
    }
    std::vector<std::vector<size_t>> graph(n + 1);
    for (size_t i = 1; i < n + 1; ++i) {
        size_t quan = 0;
        std::cin >> quan;
        for (size_t j = 0; j < quan; ++j) {
            size_t det = 0;
            std::cin >> det;
            graph[i].push_back(det);
        }
    }
    std::vector<bool> used(n + 1);
    std::vector<size_t> order;
    size_t min_time = 0;
    dfs(1, graph, times, used, order, min_time);
    std::cout << min_time << " " << order.size() << std::endl;
    for (auto now: order) {
        std::cout << now << " ";
    }
}
