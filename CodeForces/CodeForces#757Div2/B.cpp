#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::pair<int, int> > v;
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            v.push_back({a, i + 1});
        }
        std::sort(v.begin(), v.end());
        std::reverse(v.begin(), v.end());
        std::vector<int> sol(n + 1, 0);
        int l = 0;
        int r = 0;
        bool ri = true;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (ri) {
                ri = false;
                r++;
                sol[v[i].second] = r;

                res += (ll)(2LL * (ll)std::abs(r) * (ll)v[i].first);
            } else {
                ri = true;
                l--;
                sol[v[i].second] = l;
                res += (ll)(2LL * (ll)std::abs(r) * (ll)v[i].first);
            }
        }
        std::cout << res << "\n";
        for (int i = 0; i <= n; i++) {
            if (i)
                std::cout << " ";
            std::cout << sol[i];
        }
        std::cout << "\n";
    }
    return 0;
}