#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> coins;
    coins.resize(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
        sum += coins[i];
    }

    std::vector<int> dp(sum + 1);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (dp[j] == 1 && j + coins[i] <= sum) {
                dp[j + coins[i]] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= sum; i++) {
        if (dp[i] == 1) {
            count++;
        }
    }
    std::cout << count << std::endl;
    
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            std::cout << i << " ";
        }
    }   
    std::cout << std::endl;
    return 0;
}