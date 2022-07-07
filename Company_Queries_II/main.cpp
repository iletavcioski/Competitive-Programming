#include <iostream>
#include <vector>


std::vector<int> tree[200002];
std::vector<int> dp(200002, 0);
int lca[200002][19];

void dfs(int x, int prev, int level) {
    dp[x] = level;
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }
        lca[next][0] = x;
        dfs(next, x, level + 1); 
    }
}

int query(int a, int b) {
    if (dp[a] > dp[b]) {
        for (int j = 18; j >= 0; j--) {
            if (dp[a] - dp[b] >= 1 << j) {
                a = lca[a][j];
            }
        }
    }

    if (dp[b] > dp[a]) {
        for (int j = 18; j >= 0; j--) {
            if (dp[b] - dp[a] >= 1 << j) {
                b = lca[b][j];
            }
        }
    }

    if (a == b) {
        return a;
    }
    
    for (int j = 18; j >= 0; j--) {
        if (dp[a] >= 1 << j && lca[a][j] != lca[b][j]) {
            a = lca[a][j];
            b = lca[b][j];
        }
    }
    return lca[a][0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int a;
        std::cin >> a;
        tree[a].push_back(i);
    }

    for (int i = 0; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = -1;
        }
    }

    dfs(1, 0, 0);

    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            if (lca[j][i - 1] != -1) 
                lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << query(a, b) << std::endl;
    }
    return 0;
}