#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

std::vector<std::vector<int> > graph;
std::vector<std::vector<int> > rgraph;
std::stack<int> sorted_nodes;
std::vector<bool> vis1(100000, false);
std::vector<bool> vis2(100000, false);
std::vector<std::vector<int> > scc;
std::vector<int> res;
std::vector<int> cycle;

void topo_sort(int x) {
    if (vis1[x])
        return;
    vis1[x] = true;

    for (int next : graph[x]) {
        topo_sort(next);
    }
    sorted_nodes.push(x);
}

void dfs(int x, int main) {

    if (res.size() > 2 and res[0] == res[res.size() - 1] and cycle.size() == 0) {
        std::reverse(res.begin(), res.end());
        cycle = res;
        return;
    }
    if (vis2[x])
        return;
    vis2[x] = true;

    for (int next : rgraph[x]) {
        res.push_back(next);
        dfs(next, main);
        res.pop_back();
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec;

    graph.insert(graph.begin(), n, vec);
    rgraph.insert(rgraph.begin(), n, vec);
    scc.insert(scc.begin(), n, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }


    for (int i = 0; i < n; i++) {
        topo_sort(i);
    }


    while (!sorted_nodes.empty()) {
        res.clear();
        res.push_back(sorted_nodes.top());
        dfs(sorted_nodes.top(), sorted_nodes.top());
        sorted_nodes.pop();
    }

    if (cycle.size()) {
        std::cout << cycle.size() << "\n";
        for (int i : cycle) {
            std::cout << i + 1 << " ";
        }
        std::cout << "\n";
        return 0;
    }

    std::cout << "IMPOSSIBLE\n";
    return 0;
}