#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > graph;

std::vector<int> vis(100001, 0);
std::vector<int> res;
bool dfs(int x, int prev) {
    //std::cout << "vleze" << " " << x << std::endl;
    if (vis[x]) {
        res.push_back(x);
        return true;
    }

    vis[x] = true;
    bool cnt = false;
    for (int next : graph[x]) {
        if (next != prev) {
            cnt = dfs(next, x);
            if (cnt) {
                break;
            }
        }
    }
    if (cnt) {
        if (res.size() > 1 && res[0] != res[res.size() - 1]) {
            res.push_back(x);
        } else if (res.size() == 1 && res[0] != x) {
            res.push_back(x);
        }
    }
    return cnt;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();


    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec;
    graph.insert(graph.begin(), n + 1, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, 0)) {
                break;
            }
        }
    }
    //dfs(1, 0);

    std::reverse(res.begin(), res.end());
    if (res.size() == 0) {
        std::cout << "IMPOSSIBLE" << '\n';
    } else {
        std::cout << res.size() << std::endl;
        for (int i = 0; i < res.size(); i++) {
            std::cout << res[i] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}