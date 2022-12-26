#include <iostream>
#include <vector>

const long long mod = 1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> x;
    x.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    long long dp[2][101];
    for (int i = 0; i <= 100; i++) {
        dp[0][i] = dp[1][i] = 0;
    }

    int a = 0, b = 1;
    if (x[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[a][i] = 1;
        }
    } else {
        dp[a][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[b][j] = 0;
        }
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                if (j - 1 >= 1) {
                    dp[b][j] += dp[a][j - 1];
                    dp[b][j] %= mod;
                }
                dp[b][j] += dp[a][j];
                dp[b][j] %= mod;
                if (j + 1 <= m) {
                    dp[b][j] += dp[a][j + 1];
                    dp[b][j] %= mod;
                }
            }
        } else {
            int j = x[i];
            if (j - 1 >= 1) {
                dp[b][j] += dp[a][j - 1];
                dp[b][j] %= mod;
            }
            dp[b][j] += dp[a][j];
            dp[b][j] %= mod;
            if (j + 1 <= m) {
                dp[b][j] += dp[a][j + 1];
                dp[b][j] %= mod;
            }
        }
        std::swap(a, b);
    }

    long long res = 0;
    for (int i = 1; i <= m; i++) {
        res += dp[a][i];
        res %= mod;
    }
    std::cout << res << std::endl;
    return 0;
}