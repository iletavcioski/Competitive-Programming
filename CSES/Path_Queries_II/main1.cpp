#include <iostream>
#include <vector>
#include <climits>
 
const int MIN = INT_MIN;
const int N = 200000;
 
int segment_tree[4 * N];
int _index[N];
int max_subtree[N];
int lca[N][19];
int euler_values[N];
int heavy_parent[N];
int end_index[N];
int depth[N];
int values[N];
 
 
void update_segment_tree(int l, int r, int p, int pos, int value, int buffer) {
    if (l == r && l == pos) {
        segment_tree[buffer + p] = value;
        return;
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
    euler_values[total_nodes] = values[current_node];
    _index[current_node] = total_nodes++;
    heavy_parent[current_node] = heavy_node;
 
    if (max_subtree[current_node] == -1 || max_subtree[current_node] == previous_node) {
 
        end_index[heavy_node] = total_nodes - 1;
        if (heavy_node == -1) {
            end_index[current_node] = total_nodes - 1;
        }
        return;
    }
    
    if (heavy_path) {
        dfs_hld(tree, max_subtree[current_node], current_node, heavy_node, true);
    } else {
        dfs_hld(tree, max_subtree[current_node], current_node, current_node, true);
    }
 
    for (int next_node : tree[current_node]) {
        if (next_node != max_subtree[current_node] && next_node != previous_node) {
            dfs_hld(tree, next_node, current_node, -1, false);
        }
    }
}
 
 
 
void update_hld(int node, int value) {
    int node_index = _index[node];
    int heavy_node = heavy_parent[node];
    int start_index = _index[node];
    int end_index_ = end_index[node];
    if (heavy_node != -1) {
        start_index = _index[heavy_node];
        end_index_ = end_index[heavy_node];
    }
 
    update_segment_tree(start_index, end_index_, 1, node_index, value, 3 * start_index);

}
 
void build_hld(int n) {
    for (int i = 0; i < n; i++) {
        update_hld(i, values[i]);
    }
}
 
 
int find_lca(int a, int b) {
    if (depth[a] < depth[b]) {
        std::swap(a, b);
    }
    for (int i = 18; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = lca[a][i];
        }
    }


    for (int i = 18; i >= 0; i--) {
        if (lca[a][i] != lca[b][i]) {
            a = lca[a][i];
            b = lca[b][i];
        } 
    }
    if (a == b) {
        return a;
    }
    return lca[a][0];
}
 
int query_path_hld(int node, int ancestor) {
    if (node == 15 && ancestor == 0) {
        bool cc = false;
    }
    int result = std::max(values[node], values[ancestor]);
    while (depth[node] > depth[ancestor]) {
        if (heavy_parent[node] == -1) {
            int start_index = _index[node];
            result = std::max(values[node], result);
            node = lca[node][0];
        } else if (depth[heavy_parent[node]] > depth[ancestor]) {
            int start_index = _index[heavy_parent[node]];
            int end_index_ = end_index[heavy_parent[node]];
            result = std::max(query(start_index, end_index[heavy_parent[node]], 1, start_index, _index[node], 3 * start_index), result);
            node = heavy_parent[node];
        } else {
            int start_index = _index[heavy_parent[node]];
            int end_index_ = end_index[heavy_parent[node]];
            int node_index = _index[node];
            result = std::max(query(start_index, end_index_, 1, _index[ancestor], node_index, 3 * start_index), result);
            break;
            node = heavy_parent[node];
        }
    }
    return result;
}
 
int query_hld(int a, int b) {
    int ancestor = find_lca(a, b);
    return std::max(query_path_hld(a, ancestor), query_path_hld(b, ancestor));
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
 
 
    int n, q;
    std::cin >> n >> q;
 
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
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
 
    dfs_lca(tree, 0, -1, 0);
    calculate_lca(n);
    dfs_subtree(tree, 0, -1);
    dfs_hld(tree, 0, -1, -1, false);
 
 
    build_hld(n);
 
 
    for (int i = 0; i < q; i++) {
        int type;
        std::cin >> type;
 
        if (type == 1) {
            int node, value;
            std::cin >> node >> value;
            node--;
            update_hld(node, value);
            values[node] = value;
        } else {
            int a, b;
            std::cin >> a >> b;
            a--;
            b--;
            std::cout << query_hld(a, b) << " ";
        }
    }
    std::cout << "\n";
 
    return 0;
 
}