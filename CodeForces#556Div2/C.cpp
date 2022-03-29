#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<int> v;
    v.resize(n);

    int sum = 0;
    int ones = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        sum += v[i];
        if (v[i] == 1) {
            ones++;
        }
    }

    std::sort(v.begin(), v.end());
    
    if (ones > 0) {
        if (sum % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                std::swap(v[i], v[i + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) {
            std::cout << " ";
        }
        std::cout << v[i];
    }
    std::cout << "\n";
    return 0;
}