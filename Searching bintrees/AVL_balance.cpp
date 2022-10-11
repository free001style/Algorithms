//Дерево называется АВЛ-сбалансированным, если для любой
// его вершины высота левого и правого поддерева для этой
// вершины различаются не более чем на 1.

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

//    void print() {
//        if (AVL(root)) {
//            std::cout << "YES";
//        } else {
//            std::cout << "NO";
//        }
//    }
//
//    int height(node* node) {
//        if (node == 0) return 0;
//        return 1 + std::max(height(node->left), height(node->right));
//    }
//    int AVL(node* rot) {
//        if (rot == 0)
//            return 1;
//        int lh = height(rot->left);
//        int rh = height(rot->right);
//        if (abs(lh - rh) <= 1 && AVL(rot->left) && AVL(rot->right)) return 1;
//        return 0;
//    }
    int AVL(node *rot) {
        if (rot == 0)
            return 1;
        int h1 = AVL(rot->left);
        int h2 = AVL(rot->right);
        if (h1 == 0 || h2 == 0 || abs(h1 - h2) > 1)
            return 0;
        else
            return std::max(h1, h2) + 1;
    }

    void print() {
        if (AVL(root)) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
    }
};


int main() {
    int tmp = 0;
    std::cin >> tmp;
    tree t;
    while (tmp != 0) {
        t.add(tmp);
        std::cin >> tmp;
    }
    t.print();
}
