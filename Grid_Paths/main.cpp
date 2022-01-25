#include <iostream>

long long dp[1001][1001];
const long long mod = 1000000007;
int main() {
    int n;
    std::cin >> n;
    
    
    char grid[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    if (grid[0][0] == '.') {
        dp[0][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    std::cout << dp[n - 1][n - 1] << std::endl;
}