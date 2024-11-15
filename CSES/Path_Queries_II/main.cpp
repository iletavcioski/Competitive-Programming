#include <bits/stdc++.h>

const int MIN = INT_MIN;
const int N = 200000;

int segment_tree[3 * N];
std::vector<int> tree[N];
int _index[N];
int max_subtree[N];
int lca[N][19];
int heavy_parent[N];
int depth[N];
int values[N];
int n;

int I = -1;
int J = -1;
int POS = -1;
int VAL = -1;
void update_segment_tree(int l = 0, int r = n - 1, int p = 1) {
    if (l == r && l == POS) {
        segment_tree[p] = VAL;
        return;
    }

    if (l > POS || r < POS) {
        return;
    }

    update_segment_tree(l, (l + r) / 2, 2 * p);
    update_segment_tree((l + r)  / 2 + 1, r, 2 * p + 1);

    segment_tree[p] = std::max(segment_tree[2 * p], segment_tree[2 * p + 1]);
}

int query(int l = 0, int r = n - 1, int p = 1) {
    if (l >= I && r <= J) {
        return segment_tree[p];
    }

    if (l > J || r < I) {
        return MIN;
    }

    return std::max(query(l, (l + r)  / 2, 2 * p), query((l + r) / 2 + 1, r, 2 * p + 1));
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
    update_segment_tree();
    _index[current_node] = total_nodes++;
    heavy_parent[current_node] = heavy_node;

    if (max_subtree[current_node] == -1) {
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
            J = _index[node];
            I = _index[heavy_parent[node]];
            result = std::max(query(), result);
            node = heavy_parent[node];
        } else {
            J = _index[node];
            I = _index[ancestor];
            result = std::max(query(), result);
            break;
            node = heavy_parent[node];
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


    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int node, value;
            scanf("%d%d", &node, &value);
            node--;
            POS = _index[node];
            VAL = value;
            update_segment_tree();
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
