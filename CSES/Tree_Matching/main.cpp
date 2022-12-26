#include <iostream>
#include <vector>


std::vector<int> tree[200001];
std::vector<int> dp_included(200001, 0);
std::vector<int> dp_excluded(200001, 0);

void dfs(int x, int prev) {

    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        } 
        dfs(next, x);
        dp_excluded[x] += std::max(dp_excluded[next], dp_included[next]);
        
    }
    int max = 0;
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        max = std::max(dp_excluded[x] - std::max(dp_excluded[next], dp_included[next]) + 1 + dp_excluded[next], max);
    }
    dp_included[x] = max;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);
    std::cout << std::max(dp_included[1], dp_excluded[1]) << std::endl;
    return 0;
}