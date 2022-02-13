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
        long long x, y;
        std::cin >> n >> x >> y;

        std::vector<int> v;
        v.resize(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
            cnt += (v[i] % 2);
        }

        int b = x % 2;
        int e = y % 2;

        b += cnt;
        b %= 2;
        if (b == e) {
            std::cout << "Alice" << '\n';
        } else {
            std::cout << "Bob" << '\n';
        }

        

        
    }


    return 0;
}