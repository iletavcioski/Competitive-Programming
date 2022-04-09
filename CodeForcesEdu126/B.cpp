#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        ll n;
        std::cin >> n;
        ll n1 = n;
        ll count = 0;
        ll mod = 32768;
        if (n == 0) {
            std::cout << 0 << " ";
        }
        
        while (n * 2 <= mod) {
            count++;
            n *= 2;
        }
        count += (mod - n);
        ll count2 = 0;

        n = n1;
        if (n % 2) {
            n++;
            count2++;
        }
        while (n != 0) {
            count2++;
            if (count2 > count) {
                break;
            }
            n *= 2;
            n %= mod;
        }
        
        std::cout << std::min(count, count2) << " ";


    }
    std::cout << "\n";

    return 0;
}