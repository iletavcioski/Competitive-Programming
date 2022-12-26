#include <iostream>

int dp[501][501];

int rec(int height, int width) {
    if (height == width) {
        dp[height][width] = 0;
        return 0;
    }

    if (dp[height][width] != -1) {
        return dp[height][width];
    }
    int min = 1e9;
    for (int i = 1; i < height; i++) {
        min = std::min(rec(height - i, width) + rec(i, width), min);
    }

    for (int i = 1; i < width; i++) {
        min = std::min(rec(height, width - i) + rec(height, i), min);
    }

    dp[height][width] = min + 1;
    return dp[height][width];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -1;
        }
    }

    std::cout << rec(n, m) << std::endl;
}