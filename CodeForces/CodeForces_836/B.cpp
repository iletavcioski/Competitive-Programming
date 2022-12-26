#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        if (n % 2) {
            for (int i = 0; i < n; i++) {
                if (i) {
                    std::cout << " ";
                }
                std::cout << 100;
            }
            std::cout << std::endl;
        } else {
            
        }
    }


    return 0;
}