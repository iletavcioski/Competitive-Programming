#include <iostream>
#include <vector>
#include <queue>

struct state {
    int bm;
    int val;
    int len;
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> ar;
    ar.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }

    int dp[n][1 << n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    std::queue<state> q;
    q.push({0, 0, 0});
    int res = n - 1;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p.bm == (1 << n) - 1) {
            res = std::min(res, p.len);
        }

        for (int i = 0; i < n; i++) {
            if (!((1 << i) & p.bm)) {
                if (dp[p.len][p.bm | (1 << i)] > p.val + ar[i] && p.val + ar[i] <= m) {
                    dp[p.len][p.bm | (1 << i)] = p.val + ar[i];
                    q.push({p.bm | (1 << i), p.val + ar[i], p.len});
                } else if (dp[p.len + 1][p.bm | (1 << i)] > ar[i] && p.val + ar[i] > m) {
                    dp[p.len + 1][p.bm | (1 << i)] = ar[i];
                    q.push({p.bm | (1 << i), ar[i], p.len + 1});
                }
            }
        }

    }
    std::cout << res + 1 << '\n';

    return 0;
}