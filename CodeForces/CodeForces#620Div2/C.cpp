#include <bits/stdc++.h>

typedef long long ll;

struct guest {
    int t;
    int l;
    int h;
};

bool check(guest x, guest y) {
    if (y.l >= x.l && y.l <= x.h) {
        return true;
    }

    if (y.h >= x.l && y.h <= x.h) {
        return true;
    }

    if (x.l >= y.l && x.l <= y.h) {
        return true;
    }

    if (x.h >= y.l && x.h <= y.h) {
        return true;
    }

    if (x.h < y.l && (y.l - x.h) <= (y.t - x.t)) {
        return true;
    }

    if (y.h < x.l && (x.l - y.h) <= (y.t - x.t)) {
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int q;
    std::cin >> q;

    while (q--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<guest> v;
        v.push_back({0, m, m});
        for (int i = 0; i < n; i++) {
            int t, l, h;
            std::cin >> t >> l >> h;
            v.push_back({t, l, h});
        }

        bool cc = true;
        for (int i = 0; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!check(v[i], v[j])) {
                    cc = false;
                }
            }
        }
        std::cout << (cc ? "YES" : "NO") << "\n";
    }
    
    return 0;
}