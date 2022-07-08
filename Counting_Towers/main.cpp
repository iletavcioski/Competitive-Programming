#include <iostream>
#include <vector>

const long long mod = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::vector<long long> dp(1000001, 0);
    std::vector<long long> dp1(1000001, 0);
    dp1[1] = 1;

    for (int i = 2; i <= 1000000; i++) {
        dp1[i] = dp1[i - 1];
        dp1[i] *= 2;
        dp1[i] %= mod;
    }

    for (int i = 1; i <= 1000000; i++) {
        dp1[i] *= dp1[i];
        dp1[i] %= mod;
    }

    long long count;
    dp[1] = dp1[1] + 1;
    count = dp[1];

    for (int i = 2; i <= 1000000; i++) {
        dp1[i] += dp1[i - 1];
        dp1[i] %= mod;
    }

    for (int i = 2; i <= 1000000; i++) {
        
        dp[i] += count + dp1[i] + 1;
        dp[i] %= mod;
        count += dp[i];
        count %= mod;
    }

    
    std::cout << dp[6] << std::endl;
    
    /*
    int t;
    std::cin >> t;

    while (t--) {
        int num;
        std::cin >> num;
        std::cout << dp[num] << std::endl;
    }
    */
    
}