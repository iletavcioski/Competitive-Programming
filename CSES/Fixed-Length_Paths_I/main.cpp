#include <iostream>
#include <vector>

const int N = 200002;
int cnt[N];
int max_depth;
int subtree_size[N];
std::vector<int> tree[N];
bool visited_centroid[N];
long long result = 0;
int k;

int dfs_subtree(int current_node, int previous_node) {
    subtree_size[current_node] = 1;
    for (int next_node : tree[current_node]) {
        if (next_node == previous_node || visited_centroid[next_node]) {
            continue;
        }
        subtree_size[current_node] += dfs_subtree(next_node, current_node);
    }
    return subtree_size[current_node];
}

void dfs(int current_node, int previous_node, int depth, bool calculate) {
    if (depth > k) {
        return;
    }
    if (!calculate)
        cnt[depth]++;
    max_depth = std::max(max_depth, depth);
    if (calculate) {
        result += (long long)cnt[k - depth];
    }
    for (int next_node : tree[current_node]) {
        if (next_node == previous_node || visited_centroid[next_node]) {
            continue;
        }
        dfs(next_node, current_node, depth + 1, calculate);
    }
}

int find_centroid(int current_node, int previous_node, int number_of_nodes) {
    for (int next_node : tree[current_node]) {
        if (next_node == previous_node || visited_centroid[next_node]) {
            continue;
        }
        if (subtree_size[next_node] >= number_of_nodes) {
            return find_centroid(next_node, current_node, number_of_nodes);
        }
    }
    return current_node;
}

void solution(int node) {
    int all_nodes = dfs_subtree(node, -1);
    int centroid = find_centroid(node, -1, ((all_nodes + 1) / 2));

    visited_centroid[centroid] = true;
    cnt[0] = 1;
    max_depth = 0;
    for (int next_node : tree[centroid]) {
        if (!visited_centroid[next_node]) {
            dfs(next_node, centroid, 1, true);
            dfs(next_node, centroid, 1, false);

        }
    }
    //std::cout << "CENTROID: " << centroid << " SOLUTION: " << result << std::endl;

    std::fill(cnt, cnt + max_depth + 1, 0);
    for (int next_node : tree[centroid]) {
        if (!visited_centroid[next_node]) {
            solution(next_node);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solution(0);
    std::cout << result << std::endl;
    return 0;
}