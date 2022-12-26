#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    int x;
    std::cin >> x;

    long long all = 0;
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        all += a;
        v.push_back(a);
    }
    if (all < x) {
        std::cout << 0 << "\n";
        return 0;
    }
    std::map<int, int> map;

   
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