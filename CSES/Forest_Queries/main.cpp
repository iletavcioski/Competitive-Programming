#include <iostream>

char mat[1001][1001];
int dp[1001][1001];
int main() {
    int n;
    std::cin >> n;
    int q;
    std::cin >> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (mat[i][j] == '*') + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int y1, x1, y2, x2;
        std::cin >> y1 >> x1 >> y2 >> x2;

        std::cout << dp[y2][x2] - dp[y1 - 1][x2] - dp[y2][x1 - 1] + dp[y1 - 1][x1 - 1] << "\n"; 
    }

    return 0;
}