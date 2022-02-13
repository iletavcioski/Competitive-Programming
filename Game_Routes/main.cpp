#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const long long mod = 1000000007;
std::vector<std::vector<int> > graph;
std::vector<bool> vis(100001, false);
std::vector<int> top;

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    
    vis[x] = true;
    for (int next : graph[x]) {
        dfs(next);
    }
    top.push_back(x);

    return;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec;
    graph.insert(graph.begin(), n + 1, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);    
    }

    std::vector<long long> dp(n + 1, 0);
    

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    std::reverse(top.begin(), top.end());

    dp[1] = 1;
    for (int node : top) {
        for (int next : graph[node]) {
            dp[next] += dp[node];
            dp[next] %= mod;
        }
    }

    std::cout << dp[n] << std::endl;
    return 0;
}