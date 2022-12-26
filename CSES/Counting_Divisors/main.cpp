#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::vector<int> dp(1000000 + 1, 0);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            dp[j]++;
        }
    }

    int t;
    std::cin >> t;

    while (t--) {
        int x;
        std::cin >> x;
        std::cout << dp[x] << "\n";
    }
    return 0;
}