#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    ll res = 0;

    std::vector<ll> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    for (int i = 1; i < n; i++) {
        v[i] += res;
        if (v[i] < v[i - 1]) {
            res += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    std::cout << res << "\n";
    return 0;
}