#include <iostream>
#include <vector>

const long long mod = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    static long long dp[1000001][2];

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        dp[i][0] = (dp[i - 1][1] + (2 * dp[i - 1][0]) % mod) % mod;
        dp[i][1] = ((4LL * dp[i - 1][1]) % mod + dp[i - 1][0]) % mod;
    }

    int t;
    std::cin >> t;

    while (t--) {
        int num;
        std::cin >> num;
        std::cout << (dp[num][0] + dp[num][1]) % mod << std::endl;
    }

    return 0;
}