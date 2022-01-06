#include <bits/stdc++.h>

int visited[100001];
std::vector<std::vector<int> > graph;
bool impossible = false;
void dfs(int x, int team) {
    visited[x] = team;
    for (int next : graph[x]) {
        if (!visited[next]) {
            if (team == 1) {
                dfs(next, 2);
            } else {
                dfs(next, 1);
            }
        } else if (visited[next] == team) {
            impossible = true;
        }
    }    
    
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vec;
    graph.insert(graph.begin(), n, vec);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, 1);
        }
    }

    if (impossible) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << visited[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}