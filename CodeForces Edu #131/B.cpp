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
        
        std::vector<bool> vis(n + 1, false);
        std::cout << 2 << std::endl;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                std::cout << i << " ";
                int j = i;
                while (j <= n) {
                    j *= 2;
                    if (j <= n and !vis[j]) {
                        std::cout << j << " ";
                        vis[j] = true;
                    }
                }
                vis[i] = true;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}