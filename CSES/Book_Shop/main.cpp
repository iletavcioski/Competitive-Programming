#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> price;
    price.resize(n);
    std::vector<int> pages;
    pages.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> pages[i];
    }
    
    std::vector<int> dp(x + 1, -1);
    dp[0] = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (dp[j] != -1 && j + price[i] <= x) {
                dp[j + price[i]] = std::max(dp[j + price[i]], dp[j] + pages[i]);
                max = std::max(max, dp[j + price[i]]);
            }
        }
    }

    std::cout << max << std::endl;
    return 0;
}