#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        int n, l, r, k;
        std::cin >> n >> l >> r >> k;

        std::vector<int> v;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }

        std::sort(v.begin(), v.end());
        int cnt = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= l && v[i] <= r && sum + v[i] <= k) {
                sum += v[i];
                cnt++;
            }
        }
        std::cout << cnt << "\n";
    }
    return 0;
}