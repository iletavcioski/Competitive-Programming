#include <iostream>
#include <vector>

// Fenwick Tree
void update(std::vector<int> &fenwick_tree, int index, int value) {
    while (index < fenwick_tree.size()) {
        fenwick_tree[index] += value;
        index += index & (-index); 
    }
}

long long query(std::vector<int> &fenwick_tree, int index) {
    long long sum = 0;
    while (index > 0) {
        sum += fenwick_tree[index];
        index -= index & (-index);
    }
    return sum;
}

std::vector<int> euler_path;
void dfs(std::vector<std::vector<int> > &tree, int current_node, int previous_node) {
    euler_path.push_back(current_node);

    for (int next_node : tree[current_node]) {
        if (current_node == previous_node) {
            dfs(tree, next_node, current_node);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    std::vector<int> values(0, n);

    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }

    std::vector<int> tree[n];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    



}
