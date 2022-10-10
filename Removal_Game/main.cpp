#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    static long long dp[5005][5005][2];

    int start = 0;
    if (n % 2 == 0) {
        start = 1;
    }

    std::vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> dp[i][i][start];
        v[i] = dp[i][i][start];
    }

    int other = start + 1;
    other %= 2;

    for (int i = 1; i < n; i++) {
        start++;
        start %= 2;
        other++;
        other %= 2;
        for (int j = 0; j <= n - i; j++) {
            if (dp[j][j + i - 1][start] + v[j + i] > dp[j + 1][j + i][start] + v[j]) {
                dp[j][j + i][start] = dp[j][j + i - 1][start] + v[j + i];
                dp[j][j + i][other] = dp[j][j + i - 1][other];
            } else {
                dp[j][j + i][start] = dp[j + 1][j + i][start] + v[j];
                dp[j][j + i][other] = dp[j + 1][j + i][other];
            }
        }
    }

    
    std::cout << dp[0][n - 1][0] << std::endl;
    return 0;
}