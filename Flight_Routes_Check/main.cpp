#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int> > rgraph;
std::vector<std::vector<int> > graph;
std::vector<bool> vis(100001, false);
std::vector<bool> vis2(100001, false);
std::stack<int> stack;

void topological(int x) {
    if (vis[x]) {
        return;
    }
    vis[x] = true;

    for (int next : graph[x]) {
        topological(next);
    }
    stack.push(x);
}

std::vector<int> nodes;
std::vector<std::vector<int> > scc;

void dfs(int x) {
    if (vis2[x]) {
        return;
    }
    vis2[x] = true;
    nodes.push_back(x);

    for (int next : rgraph[x]) {
        dfs(next);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec;
    rgraph.insert(rgraph.begin(), n + 1, vec);
    graph.insert(graph.begin(), n + 1, vec);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            topological(i);
        }
    }

    while (!stack.empty()) {
        nodes.clear();
        int top = stack.top();
        stack.pop();
        if (!vis2[top]) {
            dfs(top);
            scc.push_back(nodes);
        }
    }

    if (scc.size() == 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
        std::cout << scc[1][0] << " " << scc[0][0] << "\n";
    }

    return 0;
}