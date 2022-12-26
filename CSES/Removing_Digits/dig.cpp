#include <iostream>

#define MAXI  1e9
int main() {
    int n;
    std::cin >> n;

    int dp[2][11];
    
    int n2 = n;
    int a = 0, b = 1;
    for (int i = 0; i <= 10; i++) {
        dp[a][i] = MAXI;
        dp[b][i] = MAXI;
    }

    while (n2 > 0) {
        dp[a][n2 % 10] = n;
        n2 /= 10;
    }
    int cnt = 0;
    bool end = false;
    while (!end) {
        for (int i = 0; i <= 10; i++) {
            if (dp[a][i] == 0) {
                end = true;
                break;
            }
        }
        
        /*
        for (int i = 0; i <= 10; i++) {
            std::cout << dp[a][i] << " ";
        }
        std::cout << std::endl;
        */
        if (end) {
            break;
        }
        for (int i = 0; i <= 10; i++) {
            if (dp[a][i] != MAXI) {
                n2 = dp[a][i] - i;
                if (n2 == 0) {
                    dp[b][0] = 0;
                }
                while (n2 > 0) {
                    dp[b][n2 % 10] = std::min(dp[b][n2 % 10], dp[a][i] - i);
                    n2 /= 10;
                }
            }
        }

        cnt++;
        std::swap(a, b);
        for (int i = 0; i <= 10; i++) {
            dp[b][i] = MAXI;
        }
    }
    
    std::cout << cnt << std::endl;

    return 0;
}