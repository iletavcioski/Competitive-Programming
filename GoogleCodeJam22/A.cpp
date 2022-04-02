#include <bits/stdc++.h>

typedef long long ll;

int main() {

    int t;
    std::cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        std::cin >> n >> m;
        std::cout << "Case #" << tt << ":" << std::endl;
        std::cout << "..+";
        for (int i = 0; i < m - 1; i++) {
            std::cout << "-+";
        }
        std::cout << std::endl;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                std::cout << "..|";
                for (int j = 0; j < m - 1; j++) {
                    std::cout << ".|";
                }
            } else {
                std::cout << "|";
                for (int j = 0; j < m; j++) {
                    std::cout << ".|";
                }
            }
            std::cout << std::endl;
            std::cout << "+";
            for (int j = 0; j < m; j++) {
                std::cout << "-+";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}