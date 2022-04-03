#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, a, b;
    std::cin >> n >> a >> b;

    if (n == 1) {
        if (a == 0 && b == 0) {
            std::cout << 1 << "\n";
        } else {
            std::cout << -1 << "\n";
        }
    }

    if (n == 2) {
        if (a > 0) {
            std::cout << -1 << "\n";
        } else if (b == 1) {
            std::cout << "1 2" << "\n";
        } else {
            std::cout << "1 1" << "\n";
        }
    }
    
    std::cout << 1;
    int sum = 1;
    int cnt = 1;
    for (int i = 0; i < b; i++) {
        std::cout << " " << sum + 1;
        sum += sum;
        sum++;
        cnt++;
    }
    if (b == 0) {
        
    }
    for (int i = 0; i < a; i++) {
        std::cout << " " << sum + 1;
        cnt++;
        sum++;
    }
    for (int i = cnt; i < n; i++) {
        std::cout << " " << 1;
    }
    std::cout << "\n";
    return 0;
}