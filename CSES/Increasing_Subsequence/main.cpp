#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<int> v;
    v.resize(n);
    std::vector<int> dp;

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    dp.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        auto it = std::lower_bound(dp.begin(), dp.end(), v[i]);
        if (it == dp.end()) {
            dp.push_back(v[i]);
        } else {
            int idx = it - dp.begin();
            dp[idx] = v[i];
        }
    }
    std::cout << dp.size() << "\n";
}