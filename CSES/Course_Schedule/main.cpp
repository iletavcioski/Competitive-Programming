#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> top;
std::vector<std::vector<int> > graph;
std::vector<bool> vis(100001, false);
std::vector<bool> entered(100001, false);
bool cycle = false;

void dfs(int color, int x) {
    //std::cout << x << '\n';
    if (vis[x]) {
        if (entered[x]) {
            //std::cout << "IMA:" << x << "\n";
            cycle = true;
        }
        return;
    }

    vis[x] = color;
    entered[x] = true;
    for (int next : graph[x]) {
        dfs(color, next);
    }
    entered[x] = false;
    top.push_back(x);
    return;
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

    int color = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            //std::cout << i << "----" << "\n";
            dfs(++color, i);
        }
    }

    std::reverse(top.begin(), top.end());

    if (cycle) {
        std::cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    for (int x : top) {
        std::cout << x << " "; 
    }
    std::cout << "\n";
    return 0;
}