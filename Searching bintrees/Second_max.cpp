//Выведите второй по величине элемент в построенном дереве. Гарантируется, что такой найдется.

#include<iostream>
#include<vector>


struct node {
    node(int k, node *p) : key(k), parent(p) {}

    int key = 0;
    node *left = 0;
    node *right = 0;
    node *parent;

};

struct tree {
    node *root = 0;

    void add(int key) {
        if (root == 0) {
            root = new node(key, 0);
            return;
        }
        node *tmp = root;
        node *p_tmp = root;
        while (tmp != 0) {
            p_tmp = tmp;
            if (key == tmp->key) {
                return;
            }
            if (key < tmp->key) {
                tmp = tmp->left;
            } else if (key > tmp->key) {
                tmp = tmp->right;
            }
        }
        if (key < p_tmp->key) {
            p_tmp->left = new node(key, p_tmp);
        } else {
            p_tmp->right = new node(key, p_tmp);
        }
    }


};

int main() {
    int tmp = 0;
    std::cin >> tmp;
    std::vector<int> ans;
    while (tmp != 0) {
        ans.push_back(tmp);
        std::cin >> tmp;
    }
    std::sort(ans.begin(), ans.end());
    auto it = std::unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());
    std::cout << ans[ans.size() - 2];
}
