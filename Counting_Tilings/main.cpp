#include <iostream>
#include <vector>

const long long mod = 1000000007;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> bitmasks;

    for (int i = 0; i < (1 << n); i++) {
        int cnt = 0;
        bool good = true;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                cnt++;
            } else {
                if (cnt % 2) {
                    good = false;
                }
            }
        }
        if (cnt % 2) {
            good = false;
        }

        if (good) {
            bitmasks.push_back(i);
        }
    }

    long long dp[2][(1 << n)];
    for (int i = 0; i < bitmasks.size(); i++) {
        dp[0][bitmasks[i]] = 1;
    }

    int f = 0, s = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < bitmasks.size(); j++) {
            dp[s][bitmasks[i]] = 0;
        }

        for (int j = 0; j < bitmasks.size(); j++) {
            for (int k = 0; k < bitmasks.size(); k++) {
                bool good = false;
                for (int l = 0; l < n; l++) {
                    int first = bitmasks[j] & (1 << l);
                    int second = bitmasks[k] & (1 << l);
                    if ()
                }
                if (good) {
                    dp[s][bitmasks[k]] += dp[f][bitmasks[j]];
                    dp[s][bitmasks[k]] %= mod;
                }
            }
        }
    }
    
    return 0;
}