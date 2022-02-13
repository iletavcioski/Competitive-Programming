#include <iostream>
#include <queue>
#include <array>

std::vector<std::vector<std::pair<int, int> > > graph;

std::vector<int> vis(2501, 0);
std::vector<int> cyc(2501, 0);

void dfs(int x, int first, int prev, long long val) {
    //std::cout << x << std::endl;
    if (vis[x] && x == first && val > 0) {
        cyc[x] = true;
        return;
    } 
    if (vis[x]) {
        return;
    }
    vis[x] = true;
    for (auto &p : graph[x]) {
        
        dfs(p.first, first, x, val + p.second);
        
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
    std::vector<long long> dp(n + 1, -1e18);

    
    std::vector<std::pair<int, int> > vec;
    graph.insert(graph.begin(), n + 1, vec);
    std::array<long long, 3> edges[m];
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        graph[a].push_back({b, c});
        edges[i] = {a, b, c};
    }

    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
        }
        dfs(i, i, 0, 0);
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            dp[edges[j][1]] = std::max(dp[edges[j][1]], dp[edges[j][0]] + edges[j][2]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[1][i] != -1e18 && dp[i][n] != -1e18 && cyc[i]) {
            cycle = true;
        }
    }
    
    return 0;
}