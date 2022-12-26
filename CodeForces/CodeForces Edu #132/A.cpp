#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();




    int n, q;
    std::cin >> n >> q;

    long long v[n + 1];

    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }

    std::vector<long long> dp1(n + 2, 0);
    std::vector<long long> dp2(n + 2, 0);
    for (int i = 2; i <= n; i++) {
        dp1[i] += dp1[i - 1];
        dp1[i] += std::max(v[i - 1] - v[i], 0LL);
    }

    for (int i = n - 1; i >= 1; i--) {
        dp2[i] += dp2[i + 1];
        dp2[i] += std::max(v[i + 1] - v[i], 0LL);
    }

    
    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        if (a <= b) {
            std::cout << dp1[b] - dp1[a] << std::endl;
        } else {
            std::cout << dp2[b] - dp2[a] << std::endl;
        }
    }



    return 0;
}