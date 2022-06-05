#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct state {
    int bitmask;
    long long weight;
    int steps;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> ar;
    ar.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }
    std::sort(ar.begin(), ar.end());
    int dp[1 << n];
    int dp2[1 << n];

    for (int i = 0; i < (1 << n); i++) {
        dp[i] = 1e9;
        dp2[i] = 1e9;
    }

    std::queue<state> qi;
    dp[0] = 1;
    dp2[0] = 0;
    qi.push({0, 0, 1});
    while (!qi.empty()) {
        state topi = qi.front();
        qi.pop();

        if (dp[topi.bitmask] == topi.steps && dp2[topi.bitmask] < topi.weight) {
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (ar[i] + topi.weight <= m && !((1 << i) & topi.bitmask) && dp[(1 << i) | topi.bitmask] > topi.steps) {
                dp[topi.bitmask | (1 << i)] = topi.steps;
                dp2[topi.bitmask | (1 << i)] = topi.weight + ar[i];
                qi.push({topi.bitmask | (1 << i), ar[i] + topi.weight, topi.steps});
            } else if (ar[i] <= m && !((1 << i) & topi.bitmask) && dp[(1 << i) | topi.bitmask] > topi.steps + 1) {
                dp[topi.bitmask | (1 << i)] = topi.steps + 1;
                dp2[topi.bitmask | (1 << i)] = ar[i];
                qi.push({topi.bitmask | (1 << i), ar[i], topi.steps + 1});
            } else if (ar[i] + topi.weight <= m && !((1 << i) & topi.bitmask) && dp[(1 << i) | topi.bitmask] == topi.steps && dp2[(1 << i) | topi.bitmask] > ar[i] + topi.weight) {
                dp[topi.bitmask | (1 << i)] = topi.steps;
                dp2[topi.bitmask | (1 << i)] = topi.weight + ar[i];
                qi.push({topi.bitmask | (1 << i), ar[i] + topi.weight, topi.steps});
            } else if (ar[i] <= m && !((1 << i) & topi.bitmask) && dp[(1 << i) | topi.bitmask] == topi.steps + 1 &&  dp2[(1 << i) | topi.bitmask] > ar[i]) {
                dp[topi.bitmask | (1 << i)] = topi.steps + 1;
                dp2[topi.bitmask | (1 << i)] = ar[i];
                qi.push({topi.bitmask | (1 << i), ar[i], topi.steps + 1});
            }
        }
    }

    std::cout << dp[(1 << n) - 1] << "\n";
    return 0;
}