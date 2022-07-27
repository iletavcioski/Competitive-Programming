#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    
    while (t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        if (a + b + c + d == 0) {
            std::cout << 0 << "\n";
        } else if (a + b + c + d == 4) {
            std::cout << 2 << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }

    return 0;
}