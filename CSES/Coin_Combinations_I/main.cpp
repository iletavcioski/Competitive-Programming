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

    std::vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i + coins[j] <= x) {
                dp[i + coins[j]] += dp[i];
                dp[i + coins[j]] %= mod;
            }
        }
    }

    std::cout << dp[x] << std::endl;
    return 0;
}