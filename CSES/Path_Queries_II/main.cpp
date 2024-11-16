#include <bits/stdc++.h>

const int MIN = INT_MIN;
const int N = 200000;

int segment_tree[5 * N];
std::vector<int> tree[N];
int _index[N];
int max_subtree[N];
int lca[N][19];
int heavy_parent[N];
int depth[N];
int values[N];
int n;
int end_nodes[N];

int I = -1;
int J = -1;
int POS = -1;
int VAL = -1;
void update_segment_tree(int l = 0, int r = n - 1, int p = 1, int buffer = 0) {
    if (l == r && l == POS) {
        segment_tree[buffer + p] = VAL;
        return;
    }

    if (l > POS || r < POS) {
        return;
    }

    update_segment_tree(l, (l + r) / 2, 2 * p, buffer);
    update_segment_tree((l + r)  / 2 + 1, r, 2 * p + 1, buffer);

    segment_tree[buffer + p] = std::max(segment_tree[buffer + 2 * p], segment_tree[buffer + 2 * p + 1]);
}

int query(int l = 0, int r = n - 1, int p = 1, int buffer = 0) {
    if (l >= I && r <= J) {
        return segment_tree[buffer + p];
    }

    if (l > J || r < I) {
        return MIN;
    }

    return std::max(query(l, (l + r)  / 2, 2 * p, buffer), query((l + r) / 2 + 1, r, 2 * p + 1, buffer));
}



void calculate_lca(int n) {
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j < n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
}

int dfs_subtree(int current_node, int previous_node, int _depth) {
    int maxi = 0;
    int node = -1;
    int sum = 0;
    depth[current_node] = _depth;
    lca[current_node][0] = previous_node;
    for (int next_node : tree[current_node]) {
        if (next_node != previous_node) {
            int sub_size = dfs_subtree(next_node, current_node, _depth + 1);
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

void dfs_hld(int current_node, int previous_node, int heavy_node) {
    POS = total_nodes;
    VAL = values[current_node];
    _index[current_node] = total_nodes++;
    heavy_parent[current_node] = heavy_node;

    if (max_subtree[current_node] == -1) {
        end_nodes[heavy_node] = current_node;
        return;
    }
    if (max_subtree[current_node] != previous_node) {
        dfs_hld(max_subtree[current_node], current_node, heavy_node);
    }

    for (int next_node : tree[current_node]) {
        if (next_node != max_subtree[current_node] && next_node != previous_node) {
            dfs_hld(next_node, current_node, next_node);
        }
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

    int result = std::max(values[node], values[ancestor]);
    while (depth[node] > depth[ancestor]) {

        if (heavy_parent[node] == node) {
            result = std::max(values[node], result);
            node = lca[node][0];
        } else if (depth[heavy_parent[node]] > depth[ancestor]) {
            int start_node = heavy_parent[node];
            int end_node = end_nodes[heavy_parent[node]];
            J = _index[node];
            I = _index[heavy_parent[node]];
            result = std::max(query(_index[start_node], _index[end_node], 1, 4 * (_index[start_node] )), result);
            node = heavy_parent[node];
        } else {
            int start_node = heavy_parent[node];
            int end_node = end_nodes[heavy_parent[node]];
            J = _index[node];
            I = _index[ancestor];
            result = std::max(query(_index[start_node], _index[end_node], 1, 4 * (_index[start_node] )), result);
            break;

        }
    }
    return result;
}

int main() {



    int q;
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }


    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs_subtree(0, -1, 0);
    calculate_lca(n);
    dfs_hld(0, -1, 0);

    for (int i = 0; i < n; i++) {
        POS = _index[i];
        VAL = values[i];
        if (i ==2) {
            bool cc=false;
            //std::cout << heavy_parent[i] << " " << end_nodes[i] << std::endl;
        }
        update_segment_tree(_index[heavy_parent[i]], _index[end_nodes[heavy_parent[i]]], 1, 4 * (_index[heavy_parent[i]] ));
    }
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int node, value;
            scanf("%d%d", &node, &value);
            node--;
            POS = _index[node];
            VAL = value;
            update_segment_tree(_index[heavy_parent[node]], _index[end_nodes[heavy_parent[node]]], 1, 4 * (_index[heavy_parent[node]] ));
            values[node] = value;
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            int ancestor = find_lca(a, b);
            printf("%d ", std::max(query_path_hld(a, ancestor), query_path_hld(b, ancestor)));
        }
    }


    return 0;

}
