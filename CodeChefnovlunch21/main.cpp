#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int rest = n - i;
            int newm = m - rest;
            if ((i * (i - 1)) / 2 >= newm) {
                for (int j = 1; j <= i; j++) {
                    for (int k = j + 1; k <= i; k++) {
                        if (newm == 0)
                            break;
                        newm--;
                        std::cout << j << " " << k << std::endl;
                    }
                    if (newm == 0)
                        break;
                }
                for (int j = i + 1; j <= n; j++) {
                    std::cout << j - 1 << " " << j << std::endl;
                }
                break;
            } else {
                continue;
            }
        }
    }
    return 0;
}
