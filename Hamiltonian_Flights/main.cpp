#include <bits/stdc++.h>

int n, m;
int graph[20][20];
int dp[20][1 << 20];
const int mod = 1000000007;
bool vis[20][1 << 20];

void tsp(int x, int bitmask) {

    // std::cout << x << " " << bitmask  << "\n";
    if (x == 0 and bitmask != 1) {
        dp[x][bitmask] = 0;
        return;
    }
  

    vis[x][bitmask] = true;
    dp[x][bitmask] = 0;
    for (int i = 0; i < n; i++) {
        if (graph[i][x] and ((1 << x) & bitmask) and ((1 << i) & bitmask)) {
            if (!vis[i][(1 << x) ^ bitmask])
                tsp(i, (1 << x) ^ bitmask);
            int res = (((long long)(dp[i][(1 << x) ^ bitmask]) * (long long)(graph[i][x])) % mod);
            dp[x][bitmask] = (dp[x][bitmask] + res) % mod;
        }
    }
    return;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a][b]++;
    }


    dp[0][1] = 1;
    vis[0][1] = true;

    tsp(n - 1, (1 << n) - 1);
    std::cout << dp[n - 1][(1 << n) - 1] << std::endl;
    return 0;
}