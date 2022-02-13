#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int> > graph;

std::vector<int> vis(100001, 0);
std::vector<int> res;
int count = 1;
bool dfs(int x, int prev) {
    //std::cout << "vleze" << " " << x << std::endl;
    if (vis[x] == count) {
        res.push_back(x);
        return true;
    }

    if (vis[x]) {
        return false;
    }

    vis[x] = count;
    bool cnt = false;
    for (int next : graph[x]) {
        
            cnt = dfs(next, x);
            if (cnt) {
                break;
            }
        
    }
    if (cnt) {
        
            if (res.size() > 1 && res[0] != res[res.size() - 1]) {
                res.push_back(x);
            } else if (res.size() == 1){
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
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, 0)) {
                break;
            }
            count++;
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