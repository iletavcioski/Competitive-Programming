#include <bits/stdc++.h>

bool visited[100001];
std::vector<std::vector<int> > graph;

void floodfill(int x) {
    visited[x] = true;
    for (int next : graph[x]) {
        if (!visited[next]) {
            floodfill(next);
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

    std::vector<int> cities;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cities.push_back(i);
            floodfill(i);
        }
    }

    std::cout << cities.size() - 1 << std::endl;
    for (int i = 1; i < cities.size(); i++) {
        std::cout << cities[0] + 1 << " " << cities[i] + 1 << std::endl;
    }
    return 0;
}