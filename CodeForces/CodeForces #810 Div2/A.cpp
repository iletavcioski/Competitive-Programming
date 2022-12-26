#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> v(n, 0);
        int cnt = 1;
        for (int i = 1; i <= n; i += 2) {
            v[cnt] = i;
            cnt += 2;
        }

        cnt = 0;
        for (int i = 2; i <= n; i += 2) {
            v[cnt] = i;
            cnt += 2;
        }

        for (int i = 0; i < n; i++) {
            
        }
    }
    return 0;
}