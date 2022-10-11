#include <vector>
#include <iostream>

struct Node {
    int value = 0;
    Node *parent = 0;
};


void push(int value, int v, std::vector<Node *> &versions) {
    auto n = new Node;
    n->value = value;
    n->parent = versions[v];
    versions.push_back(n);
}

void pop(int v, std::vector<Node *> &versions) {
    versions.push_back(versions[v]->parent);
}

int main() {
    std::vector<Node *> versions;
    int n = 0;
    std::cin >> n;
    Node *head = new Node;
    versions.push_back(head);
    for (int i = 0; i < n; ++i) {
        int t = 0, m = 0;
        std::cin >> t >> m;
        if (m > 0) {
            push(m + versions[t]->value, t, versions);
        } else {
            pop(t, versions);
        }
    }
    size_t sum = 0;
    for (auto now: versions) {
        sum += now->value;
    }
    std::cout << sum;
    return 0;
}
