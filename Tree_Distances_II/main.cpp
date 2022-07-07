#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> tree[200002];
std::vector<long long> dp1(200002, 0);
std::vector<long long> dp2(200002, 0);
std::vector<long long> dp(200002, 0);
void dfs1(int x, int prev) {
    dp[x] = 1;
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        dfs1(next, x);
        dp[x] += dp[next];
        dp1[x] += (dp1[next] + dp[next]);

    }
}

void dfs2(int x, int prev, long long till_now, long long nodes_above) {
    dp2[x] = till_now;

    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        dfs2(next, x, till_now + nodes_above + dp1[x] - (dp1[next] + dp[next]) + (dp[x] - dp[next]), nodes_above + dp[x] - dp[next]);
    }
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

    dfs1(1, 0);
    dfs2(1, 0, 0, 0);


    long long max = 0;

    for (int i = 1; i <= n; i++) {
        //std::cout << dp1[i] << " ";
        std::cout << dp1[i] + dp2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}