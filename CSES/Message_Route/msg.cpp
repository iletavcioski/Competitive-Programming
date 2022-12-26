#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<bool> visited(n, false);
    visited[0] = true;
    std::vector<std::vector<int> > graph;
    std::vector<int> vec;
    graph.insert(graph.begin(), n, vec);
    std::vector<int> path(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::queue<int> qi;
    qi.push(0);
    std::queue<int> qs;
    qs.push(0);

    int result = -1;
    while (!qi.empty()) {
        int topi = qi.front();
        qi.pop();
        int tops = qs.front();
        qs.pop();

        if (topi == n - 1) {
            result = tops;
            break;
        }

        for (int x : graph[topi]) {
            if (!visited[x]) {
                qi.push(x);
                qs.push(tops + 1);
                visited[x] = true;
                path[x] = topi;
            }
        }
    }
    if (result == -1) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::vector<int> res;
        int y = n - 1;
        while (path[y] != -1) {
            res.push_back(y);
            y = path[y];
        }
        res.push_back(0);
        reverse(res.begin(), res.end());
        std::cout << result + 1 << std::endl;
        for (int i = 0; i <= result; i++) {
            std::cout << res[i] + 1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}