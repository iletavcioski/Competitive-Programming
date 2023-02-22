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

    int lca[n + 1][31];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; j++) {
            lca[i][j] = -1;
        }
    }
    std::vector<int> portals;
    portals.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> portals[i];
    }

    std::vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int x = i;
        while (!visited[x]) {
            lca[x][0] = portals[x];
            visited[x] = true;
            x = portals[x];
        }
    }

    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= n; j++) {
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
        }
    }
    
    while (q--) {
        int x, k;
        std::cin >> x >> k;

        for (int j = 30; j >= 0; j--) {
            if ((1 << j) <= k) {
                x = lca[x][j];
                k -= (1 << j);
            }
        }
        std::cout << x << '\n';
    }
    


    return 0;
}
