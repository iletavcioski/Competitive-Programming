#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<std::pair<int, int> > > graph;
std::vector<int> top_sort;
std::vector<bool> vis(100001, false);

void dfs(int x) {
    if (vis[x]) {
        return;
    }
    vis[x] = true;

    for (auto &next : graph[x]) {
        dfs(next.first);
    }

    top_sort.push_back(x);
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int> > vec;
    graph.insert(graph.begin(), n + 1, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        int c = 1;
        std::cin >> a >> b;
        graph[a].push_back({b, c});    
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }    
    std::reverse(top_sort.begin(), top_sort.end());

    std::vector<long long> dp(n + 1, -1);
    dp[1] = 0;
    std::vector<int> path(n + 1, -1);

    for (int node : top_sort) {
        for (auto &next : graph[node]) {
            if (dp[node] != -1 && dp[next.first] < dp[node] + next.second) {
                dp[next.first] = dp[node] + next.second;
                path[next.first] = node;
            }
        }
    }

    if (dp[n] == -1) {
        std::cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    std::vector<int> res;
    int y = n;
    res.push_back(y);
    while (path[y] != -1) {
        y = path[y];
        res.push_back(y);
    }

    std::reverse(res.begin(), res.end());

    std::cout << dp[n] + 1 << '\n';

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << '\n';

    return 0;
}