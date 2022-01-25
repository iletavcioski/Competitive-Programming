#include <iostream>
#include <vector>

#define MAXI 1e9

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> coins;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(m + 1, MAXI);
    dp[0] = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + coins[j] <= m) {
                dp[i + coins[j]] = std::min(dp[i + coins[j]], dp[i] + 1);
            }
        }
    }

    if (dp[m] == MAXI) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[m] << std::endl;
    }

    return 0;
}