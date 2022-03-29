#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m, r;
    std::cin >> n >> m >> r;
    std::vector<int> v1;
    v1.resize(n);
    std::vector<int> v2;
    v2.resize(m);


    for (int i = 0; i < n; i++) {
        std::cin >> v1[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v2[i];
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::reverse(v2.begin(), v2.end());

    if (v1[0] >= v2[0]) {
        std::cout << r << "\n";
    } else {
        std::cout << std::max(r + ((r / v1[0]) * (v2[0] - v1[0])), r) << "\n";
    }
    return 0;
}