#include <bits/stdc++.h>

int n, m;
std::vector<std::vector<int> > graph;
long long dp[20][1 << 20];
const long long modul = 1000000007;
bool visited[20][1 << 20];

void dfs(int x, int bitmask) {

}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> vec;
    graph.insert(graph.begin(), n, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    dp[0][1] = 1;
    visited[0][1] = true;

    std::queue<state> q;
    q.push({0, 1});

    while (!q.empty()) {
        state now = q.front();
        q.pop();

        for (int x : graph[now.x]) {
            if (!(now.bitmask & (1 << x))) {
                q.push({x, now.bitmask | (1 << x)});
                visited[x][now.bitmask | (1 << x)] = true;
                dp[x][now.bitmask | (1 << x)] += dp[now.x][now.bitmask];
                dp[x][now.bitmask | (1 << x)] %= modul;
            }
        }
    }

    std::cout << dp[n - 1][(1 << n) - 1] << std::endl;
    return 0;
}