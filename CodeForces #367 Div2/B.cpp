#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie();
    std::cin.tie();

    int n;
    std::cin >> n;
    
    std::vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int q;
    std::cin >> q;
    std::sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int num;
        std::cin >> num;
        std::cout << std::upper_bound(v.begin(), v.end(), num) - v.begin() << "\n";
    }
    
    return 0;
}