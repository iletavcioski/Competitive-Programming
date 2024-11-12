#include <iostream>
#include <vector>

// Fenwick Tree
void update(std::vector<long long> &fenwick_tree, int index, long long value) {
    while (index < fenwick_tree.size()) {
        fenwick_tree[index] += value;
        index += index & (-index);
    }
}

long long query(std::vector<long long> &fenwick_tree, int index) {
    long long sum = 0;
    while (index > 0) {
        sum += fenwick_tree[index];
        index -= index & (-index);
    }
    return sum;
}

std::vector<int> values;
std::vector<long long> euler_path;

void dfs(std::vector<std::vector<int> > &tree, std::vector<int> &_map, int current_node, int previous_node, long long total_sum) {
    euler_path.push_back(total_sum);
    _map[current_node] = euler_path.size() - 1;
    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            dfs(tree, _map, next_node, current_node, total_sum + values[next_node]);
        }
    }
}

int subtree_dfs(std::vector<int> &subtree_size, std::vector<std::vector<int> > &tree, int current_node, int previous_node) {
    subtree_size[current_node] = 1;

    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            subtree_size[current_node] += subtree_dfs(subtree_size, tree, next_node, current_node);
        }
    }
    return subtree_size[current_node];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;


    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        values.push_back(a);
    }

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
    std::vector<int> subtree_size(n, 0);

    std::vector<long long> fenwick_tree(n + 1, 0);

    std::vector<int> _map(n, 0);
    dfs(tree, _map, 0, -1, values[0]);
    subtree_dfs(subtree_size, tree, 0, -1);

    for (int i = 0; i < n; i++) {
        update(fenwick_tree, _map[i] + 1, values[i]);
        update(fenwick_tree, _map[i] + subtree_size[i] + 1, -values[i]);
    }

    for (int i = 0; i < q; i++) {
        int query_type;
        std::cin >> query_type;

        if (query_type == 1) {
            int s, x;
            std::cin >> s >> x;
            s--;

            long long difference = x - values[s];
            update(fenwick_tree, _map[s] + 1, difference);
            update(fenwick_tree, _map[s] + 1 + subtree_size[s], -difference);
            values[s] = x;
        } else {
            int s;
            std::cin >> s;
            s--;
            std::cout << query(fenwick_tree, _map[s] + 1)  << "\n";
        }
    }



}
