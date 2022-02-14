#include <iostream>
#include <vector>

std::vector<std::vector<int> > tree;
std::vector<int> dp(200002, 0);

int dfs(int prev, int x) {
    for (int next : tree[x]) {
        if (next != x)
            dp[x] += dfs(x, next);
    }

    return dp[x] + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vec;
    tree.insert(tree.begin(), n, vec);

    for (int i = 0; i < n - 1; i++) {
        int a;
        std::cin >> a;
        tree[a - 1].push_back(i + 1);

    }

    dfs(-1, 0);

    for (int i = 0; i < n; i++) {
        std::cout << dp[i] << " ";
    }
    std::cout << "\n";
    return 0;
}