#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int k, l, m, n, d;
    std::cin >> k >> l >> m >> n >> d;
    std::vector<int> vis(d + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= d; i++) {
        if (i % k == 0 || i % m == 0 || i % l == 0 || i % n == 0) {
            cnt++;
        }
    }
    std::cout << cnt << "\n";
    
    return 0;
}