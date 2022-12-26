#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m, q;
    std::cin >> n >> m >> q;

    long long dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = 1e18;
        }
    }
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;

        a--;
        b--;
        dist[a][b] = std::min(dist[a][b], c);
        dist[b][a] = std::min(dist[b][a], c);

    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] < 1e18) {
            std::cout << dist[a][b] << '\n';
        } else {
            std::cout << -1 << '\n';
        }
    }
    


    return 0;
}