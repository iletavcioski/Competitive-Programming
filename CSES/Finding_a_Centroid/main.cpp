#include <iostream>
#include <vector>

const int N = 200000;
int subtree_size[N];

int dfs(std::vector<std::vector<int> > &tree, int current_node, int previous_node) {
    subtree_size[current_node] = 1;

    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            subtree_size[current_node] += dfs(tree, next_node, current_node);
        }
    }
    return subtree_size[current_node];
}

int find_centroid(std::vector<std::vector<int> > &tree, int current_node, int previous_node, int n) {
    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            if (subtree_size[next_node] >= (n + 1) / 2) {
                return find_centroid(tree, next_node, current_node, n);
            }
        }
    }
    return current_node;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<std::vector<int> > tree;
    std::vector<int> vec;
    tree.insert(tree.begin(), n, vec);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(tree, 0, -1);
    std::cout << find_centroid(tree, 0, -1, n) + 1 << "\n";
}