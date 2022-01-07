#include <bits/stdc++.h>

std::vector<std::vector<int> > graph;

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

    

    return 0;
}