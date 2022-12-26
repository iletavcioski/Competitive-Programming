#include <iostream>
#include <vector>
#include <algorithm>

struct edge {
    int a, b;
    long long c;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
    std::vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c});
    }

    std::vector<long long> distances(n, 1e18);
    std::vector<int> parent(n, -1);
    std::vector<long long> prev(n, 1e18);
    distances[0] = 0;

    int cycle_node = -1;
    for (int i = 0; i < n; i++) {
        for (edge e : edges) {
            if (distances[e.b] > distances[e.a] + e.c) {
                parent[e.b] = e.a;
                distances[e.b] = distances[e.a] + e.c;
                if (i < n - 1) {
                    prev[e.b] = distances[e.b];
                } else if (prev[e.b] > distances[e.b] and cycle_node == -1){
                    cycle_node = e.b;
                }

            }
        }
    }

    if (cycle_node != -1) {
        std::cout << "YES\n";
        std::vector<int> res;
        std::vector<bool> vis(n, 0);
        res.push_back(cycle_node);

        int start = cycle_node;
        vis[start] = true;
        while (true) {
            cycle_node = parent[cycle_node];
            res.push_back(cycle_node);
            if (vis[cycle_node]) {
                break;
            }
            vis[cycle_node] = true;
        }
        std::reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {

            std::cout << res[i] + 1 << " ";
            if (res[i] == res[0] and i != 0) {
                break;
            }
        }
        std::cout << "\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}