#include <iostream>
#include <vector>

const long long mod = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    if (((n * (n + 1)) / 2) % 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int goal = ((n * (n + 1)) / 2) / 2;
    std::vector<long long> dp(goal + 1, 0);
    dp[0] = 1;
    //std::cout << goal << std::endl;
    for (int i = 1; i < n; i++) {
        for (int j = goal; j >= 0; j--) {
            if (i + j <= goal)
                dp[i + j] += dp[j];
                dp[i + j] %= mod;
        }
    }

    std::cout << dp[goal - n] << "\n";
    return 0;
}