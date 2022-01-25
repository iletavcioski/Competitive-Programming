#include <iostream>
#include <vector>

const long long mod = 1000000007;

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins;
    coins.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (coins[i] + j <= x) {
                dp[coins[i] + j] += dp[j];
                dp[coins[i] + j] %= mod;
            }
        }
    }

    std::cout << dp[x] << std::endl;
    return 0;
}