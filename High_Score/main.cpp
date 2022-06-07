#include <iostream>
#include <queue>
#include <array>

struct edge {
    int a, b;
    long long c;
};

std::vector<bool> flag(2500, false);
std::vector<bool> vis(2500, false);
std::vector<std::vector<int> > rgraph;
bool cycle = false;

void dfs(int x) {
    if (flag[x]) { 
        cycle = true;
    }

    for (int next : rgraph[x]) {
        if (!vis[next]) {
            vis[next] = true;
            dfs(next);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<edge> edges;
    std::vector<int> vec;
    rgraph.insert(rgraph.begin(), n, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        rgraph[b].push_back(a);
        edges.push_back({a, b, c});
    }

    std::vector<long long> distances(n, -1e18);
    std::vector<long long> prev(n, -1e18);
    distances[0] = 0;
    prev[0] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (edge e : edges) {
            if (distances[e.a] != -1e18) {
                distances[e.b] = std::max(distances[e.b], distances[e.a] + e.c);
                prev[e.b] = distances[e.b];
            }

        }
    }
    
    for (int i = 0; i < n; i++) {
        for (edge e : edges) {
            if (distances[e.a] != -1e18) {
                distances[e.b] = std::max(distances[e.b], distances[e.a] + e.c);
            }
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (distances[i] > prev[i]) {
            flag[i] = true;
        }
    }
    vis[n - 1] = true;
    dfs(n - 1);
    
    if (cycle) {
        std::cout << -1 << "\n";
        return 0;
    }
    std::cout << distances[n - 1] << "\n";
    
    return 0;
}