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
        std::vector<ll> a, b, v; 
        a.resize(n);
        b.resize(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
           
        }
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
           
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                std::swap(a[i] , b[i]);
            }
        }
        

        ll res = 0;
        for (int i = 0; i < n - 1; i++) {
            res += std::abs(a[i + 1] - a[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            res += std::abs(b[i + 1] - b[i]);
        }
        std::cout  << res << "\n";

    }

    return 0;
}