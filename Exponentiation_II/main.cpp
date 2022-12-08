#include <iostream>

const long long mod = 1000000007;

long long exp(int x, int e) {
    if (e == 0) {
        return 1;
    }

    if (e == 1) {
        return x;
    }

    long long res = exp(x, e / 2) * exp(x, e / 2);
    res %= mod;
    if (e % 2) {
        res *= x;
        res %= mod;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << exp(a, b * c) << "\n";
    }
}