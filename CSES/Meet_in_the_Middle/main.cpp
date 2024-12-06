#include <iostream>
#include <vector>
#include <unordered_map>
int v[41];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    int x;
    std::cin >> x;

    long long all = 0;
    int minimum = 1e9;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> v[i];
        all += v[i];
        minimum = std::min(minimum, v[i]);
    }
    if (all == x) {
        std::cout << 1 << "\n";
        return 0;
    }
    if (all < x || (all - minimum) < x) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::unordered_map<int, int> map;

   
    for (int i = 0; i < (1 << ((n + 1) / 2)); i++) {
        int cnt = 0;
        bool necini = false;
        for (int j = 0; j < (n + 1) / 2; j++) {
            if (i & (1 << j)) {
                cnt += v[j];
                if (cnt > x) {
                    necini = true;
                    break;
                }
            }
            
        }
        if (!necini)
            map[cnt]++;
    }

    long long res = 0;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        int cnt = 0;
        bool necini = false;
        for (int j = 0; j < n / 2; j++) {
            if (i & (1 << j)) {
                cnt += v[j + ((n + 1) / 2)];
                if (cnt > x) {
                    necini = true;
                    break;
                }
            }
        }
        res += map[x - cnt];
    }
    std::cout << res << std::endl;
    return 0;
}