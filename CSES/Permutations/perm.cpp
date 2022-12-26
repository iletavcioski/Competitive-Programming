#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    if (n == 3 || n == 2) {
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        for (int i = 2; i <= n; i+=2) {
            std::cout << i << " ";
        }
        
        for (int i = 1; i <= n; i+=2) {
            std::cout << i << " ";
        }

        
        std::cout << std::endl;
    }
    return 0;
}