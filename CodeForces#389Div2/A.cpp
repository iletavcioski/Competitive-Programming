#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m, k;
    std::cin >> n >> m >> k;

    bool right = true;
    if (k % 2) {
        right = false;
        k++;
    }

    k /= 2;

    std::cout << (k / m + 1 - (k % m == 0 ? 1 : 0)) << " " << (k % m == 0 ? m : k % m) << " " << (right ? "R" : "L") << "\n";
    return 0;
}