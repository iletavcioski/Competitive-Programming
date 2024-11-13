#include <iostream>
#include <vector>
#include <climits>  

const int MIN = INT_MIN;
const int N = 200000;

int segment_tree[4 * N];
int index[N];
int max_subtree[N];
int lca[N][19];
int euler_values[N];
int heavy_parent[N];
int end_index[N];
int depth[N];

void build_segment_tree(int l, int r, int p, int buffer) {
    if (l == r) {
        segment_tree[buffer + p] = euler_values[l];
        return;
    }

    build_segment_tree(l, (l + r) / 2, 2 * p, buffer);
    build_segment_tree((l + r)  / 2 + 1, r, 2 * p + 1, buffer);

    segment_tree[buffer + p] = std::max(segment_tree[buffer + 2 * p], segment_tree[buffer + 2 * p + 1]);
}

void update_segment_tree(int l, int r, int p, int pos, int value, int buffer) {
    if (l == r && l == pos) {
        segment_tree[buffer + p] = value;
    }

    if (l > pos || r < pos) {
        return;
    }

    update_segment_tree(l, (l + r) / 2, 2 * p, pos, value, buffer);
    update_segment_tree((l + r)  / 2 + 1, r, 2 * p + 1, pos, value, buffer);

    segment_tree[buffer + p] = std::max(segment_tree[buffer + 2 * p], segment_tree[buffer + 2 * p + 1]);
}

int query(int l, int r, int p, int i, int j, int buffer) {
    if (l >= i && r <= j) {
        return segment_tree[buffer + p];
    }

    if (l > j || r < i) {
        return MIN;
    }

    return std::max(query(l, (l + r)  / 2, 2 * p, i, j, buffer), query((l + r) / 2 + 1, r, 2 * p + 1, i, j, buffer));
}

void dfs_lca(std::vector<std::vector<int> > &tree, int current_node, int previous_node, int _depth) {
    depth[current_node] = _depth;
    lca[current_node][0] = previous_node;
    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            dfs_lca(tree, next_node, current_node, _depth + 1);
        }
    }
}

void calculate_lca(int n) {
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j < n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
}

int dfs_subtree(std::vector<std::vector<int> > &tree, int current_node, int previous_node) {
    int maxi = 0;
    int node = -1;
    int sum = 0;
    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            int sub_size = dfs_subtree(tree, next_node, current_node);
            if (sub_size > maxi) {
                maxi = sub_size;
                node = next_node;
            }
            sum += sub_size;
        }
    }
    max_subtree[current_node] = node;
    return sum + 1;
}

int total_nodes;

void dfs_hld(std::vector<std::vector<int> > &tree, int current_node, int previous_node, int heavy_node, bool heavy_path) {
    index[current_node] = total_nodes++;

    if (max_subtree[current_node] == -1) {
        end_index[heavy_node] = total_nodes;
        return;
    }
    if (heavy_path) {
        dfs_hld(tree, max_subtree[current_node], current_node, heavy_node, true);
    } else {
        dfs_hld(tree, max_subtree[current_node], current_node, current_node, true);
    }

    for (int next_node : tree[current_node]) {
        if (next_node != max_subtree[current_node] && next_node != previous_node) {
            dfs_hld(tree, next_node, current_node, next_node, false);
        }
    }
}



void update_hld(int node, int value) {
    int node_index = index[node];
    int heavy_node = heavy_parent[node];
    int start_index = index[heavy_node];
    int end_index_ = end_index[heavy_node];

    update_segment_tree(start_index, end_index_, 1, node_index, value, 3 * start_index);
}

void build_hld(int n) {
    for (int i = 0; i < n; i++) {
        update_hld(i, euler_values[i]);
    }
}

int query_hld(int a, int b) {

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();


    int n, q;
    std::cin >> n >> q;


    return 0;

}