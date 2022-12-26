#include <iostream>
#include <vector>
#include <stack>
#include <map>
 

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    std::vector<int> portals;
    portals.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> portals[i];
    }

    
    return 0;
}
