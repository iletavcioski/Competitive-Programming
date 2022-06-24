#include <iostream>
#include <vector>
#include <stack>

std::vector<std::vector<int> > rgraph;
std::vector<std::vector<int> > graph;
std::vector<bool> vis(100001, false);
std::vector<bool> vis2(100001, false);
std::stack<int> stack;
std::vector<int> color(100001, 0);
int col = 1;
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
    color[x] = col;

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
        int top = stack.top();
        stack.pop();
        if (!vis2[top]) {
            dfs(top);
            col++;
        }
    }

    std::cout << col - 1 << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << color[i] << " ";
    }
    std::cout << "\n";

    return 0;
}