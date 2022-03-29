#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    
    while (t--) {
        ll x, y, a, b;
        std::cin >> x >> y >> a >> b;

        ll l = 0, r = y;

        ll res = -1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (x + mid * a < y - mid * b) {
                l = mid + 1;
            } else if (x + mid * a > y - mid * b) {
                r = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        std::cout << res << "\n";
    }

    return 0;
}