#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, p;
    std::cin >> n >> p;

    std::vector<int> dp(p, 0);

    for (int i = 0; i < n; i++) {
        
        int a;
        std::cin >> a;
        std::vector<int> v;
        int pow = 0;
        ll num = 1;
        while (num * 2 <= a) {
            num *= 2;
            pow++;
        }

        //std::cout << num << "\n";
        if (pow < p) {
            dp[pow]++;
        }
    }

    
    ll res = 0;
    for (int i = 0; i < p; i++) {
        res += dp[i];
        res %= mod;
        if (i + 1 < p) {
            dp[i + 1] += dp[i];
            dp[i + 1] %= mod;
        }

        if (i + 2 < p) {
            dp[i + 2] += dp[i];
            dp[i + 2] %= mod;
        }
    }

    

    std::cout << res << "\n";
    return 0;
}