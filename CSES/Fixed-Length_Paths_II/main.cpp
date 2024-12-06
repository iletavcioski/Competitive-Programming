#include <iostream>
#include <vector>

const int N = 200002;
int cnt[200001];
int n, q;
int k1, k2;



int max_depth;
int subtree_size[N];
std::vector<int> tree[N];
bool visited_centroid[N];
long long result = 0;
int partial[N];

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
    if (depth > k2) {
        return;
    }
    if (!calculate)
        partial[depth]++;
    max_depth = std::max(max_depth, depth);

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
    cnt[0] = 0;
    max_depth = 0;
    for (int next_node : tree[centroid]) {
        if (!visited_centroid[next_node]) {
            dfs(next_node, centroid, 1, false);

            for (int i = 1; i <= max_depth; i++) {

                result += (long long)(partial[i] * (cnt[k2 - i + 1] - cnt[k1 - i]));
            }

            int all = 0;
            for (int i = 1; i <= max_depth; i++) {
                if (i <= max_depth) {
                    all += partial[i];
                }
                cnt[i + 1] += all;
            }

            std::fill(partial, partial + max_depth + 2, 0);

        }

    }
    //std::cout << "CENTROID: " << centroid << " SOLUTION: " << result << std::endl;

    std::fill(cnt, cnt + k2 + 2, 1LL);
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


    std::cin >> n >> k1 >> k2;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    std::fill(cnt, cnt + k2 + 2, 1LL);
    solution(0);
    std::cout << result << std::endl;
    return 0;
}