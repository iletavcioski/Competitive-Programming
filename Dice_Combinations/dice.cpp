#include <iostream>
#include <vector>

const long long mod = 1000000007;

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j <= n) {
                dp[i + j] += dp[i];
                dp[i + j] %= mod;
            }
        }
    }

    std::cout << dp[n] << std::endl;
    return 0;
}