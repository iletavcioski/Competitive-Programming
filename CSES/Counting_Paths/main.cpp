#include <iostream>
#include <vector>

int n;

std::vector<int> tree[200002];
std::vector<int> sol(200002, 0);
std::vector<int> rem(200002, 0);
std::vector<int> dp(200002, 0);
int lca[200002][20];

void dfs_lca(int x, int parent, int level) {
    lca[x][0] = parent;
    dp[x] = level;
    for (int next : tree[x]) {
        if (next != parent) {
            dfs_lca(next, x, level + 1);
        }
    }
}

void create_lca() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (lca[i][j - 1] != -1) {
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
    }
}

int lca_query(int a, int b) {
    if (dp[a] > dp[b]) {
        for (int j = 20; j >= 0; j--) {
            if (dp[a] - dp[b] >= 1 << j) {
                a = lca[a][j];
            }
        }
    }
 
    if (dp[b] > dp[a]) {
        for (int j = 20; j >= 0; j--) {
            if (dp[b] - dp[a] >= 1 << j) {
                b = lca[b][j];
            }
        }
    }
 
    if (a == b) {
        return a;
    }
    
    for (int j = 20; j >= 0; j--) {
        if (dp[a] >= 1 << j && lca[a][j] != lca[b][j]) {
            a = lca[a][j];
            b = lca[b][j];
        }
    }
    return lca[a][0];
}

void dfs(int x, int parent) {
    for (int next : tree[x]) {
        if (next != parent) {
            dfs(next, x);
            sol[x] += (sol[next] - (rem[next] * 2));
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int m;
    std::cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 20; j++) {
            lca[i][j] = -1;
        }
    }

    dfs_lca(1, -1, 0);
    create_lca();
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        sol[a]++;
        sol[b]++;
        rem[lca_query(a, b)]++;    
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            std::cout << " ";
        }
        std::cout << sol[i] - rem[i];
    }
    std::cout << std::endl;
    return 0;
}