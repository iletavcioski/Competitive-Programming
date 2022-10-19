#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        int portal;
        std::cin >> portal;

        portal--;
        portals.push_back(portal);
    }


    std::vector<bool> where_is_cycle(n, false);
    std::vector<int> which_cycle(n, 0);
    std::vector<int> each_cycle_length(n, 0);
    std::vector<int> position_in_cycle(n, 0);

    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            
        }
    }


    return 0;
}