//Для полученного дерева выведите список всех вершин, имеющих по два ребёнка, в порядке возрастания.

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
    std::vector<int> ans;
    node *res = 0;

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

    void print() {
        print(root);
    }

    void print(node *v) {
        if (v) {
            print(v->left);
            if (v->left && v->right) {
                std::cout << v->key << std::endl;
            }
            print(v->right);
        }
    }

};

int main() {
    tree t;
    int tmp = 0;
    std::cin >> tmp;
    while (tmp != 0) {
        t.add(tmp);
        std::cin >> tmp;
    }
    t.print();
}
