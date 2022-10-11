#include <iostream>
#include <vector>

struct Node {
    std::string code = "";
    Node *left = 0;
    Node *right = 0;
    Node *parent = 0;
};


void leaf(Node *now, std::vector<std::string> &codes) {
    if (!now) return;
    leaf(now->left, codes);
    if (!now->left and !now->right) {
        codes.push_back(now->code);
    }
    leaf(now->right, codes);
}

void destroyer(Node *now) {
    if (now) {
        destroyer(now->left);
        destroyer(now->right);
        delete now;
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        Node *root = new Node;
        Node *now;
        now = root;
        std::string s = "";
        std::cin >> s;
        for (auto ch: s) {
            if (ch == 'D') {
                Node *l_root = new Node;
                now->left = l_root;
                l_root->parent = now;
                l_root->code = l_root->parent->code + '0';
                now = l_root;
            }
            if (ch == 'U') {
                while (now->parent->right) {
                    now = now->parent;
                }
                now = now->parent;
                Node *r_root = new Node;
                now->right = r_root;
                r_root->parent = now;
                r_root->code = r_root->parent->code + '1';
                now = r_root;
            }
        }
        std::vector<std::string> codes;
        leaf(root, codes);
        std::cout << codes.size() << std::endl;
        for (const auto &code: codes) {
            std::cout << code << std::endl;
        }
        codes.clear();
        destroyer(root);
    }
}
