#include <vector>
#include <iostream>

#define MAX 100010
struct SegmentTree_Node {
    int value = 0;
    struct SegmentTree_Node *Left = 0, *Right = 0;
} *PSTree[MAX];

struct SegmentTree {
    static void build(SegmentTree_Node &V, const std::vector<int> &a, int L, int R) {
        if (L == R) {
            V.value = a[L];
            V.Left = V.Right = 0;
            return;
        }

        int Mid = (L + R) / 2;
        V.Left = new SegmentTree_Node();
        build(*V.Left, a, L, Mid);
        V.Right = new SegmentTree_Node();
        build(*V.Right, a, Mid + 1, R);
    }

    static void Update(SegmentTree_Node &V, int L, int R, int pos, int value) {
        if (L == R) {
            V.value = value;
            return;
        }

        int Mid = (L + R) / 2;
        if (pos <= Mid) {
            SegmentTree_Node *Left = new SegmentTree_Node();
            *Left = *V.Left;
            V.Left = Left;
            Update(*Left, L, Mid, pos, value);
        } else {
            SegmentTree_Node *Right = new SegmentTree_Node();
            *Right = *V.Right;
            V.Right = Right;
            Update(*Right, Mid + 1, R, pos, value);
        }
    }

    static int Get(SegmentTree_Node &V, int L, int R, int pos) {
        if (L == R) return V.value;
        int Mid = (L + R) / 2;
        if (pos <= Mid)
            return Get(*V.Left, L, Mid, pos);
        else
            return Get(*V.Right, Mid + 1, R, pos);
    }

};


int main() {
    int N = 0;
    std::cin >> N;
    std::vector<int> nums(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> nums[i];
    }
    PSTree[0] = new SegmentTree_Node();
    SegmentTree::build(*PSTree[0], nums, 0, N);
    int M = 0;
    std::cin >> M;
    int count = 1;
    for (int i = 0; i < M; ++i) {
        std::string q;
        std::cin >> q;
        if (q == "create") {
            int vertex = 0, position = 0, value = 0;
            std::cin >> vertex >> position >> value;
            SegmentTree_Node *node = new SegmentTree_Node();
            *node = *PSTree[vertex - 1];
            PSTree[count] = node;
            SegmentTree::Update(*PSTree[count++], 0, N, position, value);
        } else {
            int vertex = 0, position = 0;
            std::cin >> vertex >> position;
            std::cout << SegmentTree::Get(*PSTree[vertex - 1], 0, N, position) << std::endl;
        }
    }
    return 0;
}
