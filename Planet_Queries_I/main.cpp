#include <iostream>
#include <vector>
#include <stack>

std::vector<bool> visited(200002, false);
std::vector<bool> visited2(200002, false);
std::vector<std::vector<int> > graph;
std::vector<std::vector<int> > rgraph;
std::stack<int> stack;
std::vector<int> scc(200002, 0);

void topological(int x) {
    if (visited[x]) {
        return;
    }
    visited[x] = true;
    for (int next : graph[x]) {
        topological(next);
    }
    stack.push(x);
    return;
}

void dfs(int x, int scc_num) {
    if (scc[x]) {
        return;
    }
    scc[x] = scc_num;
    for (int next : rgraph[x]) {
        dfs(next, scc_num);
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> vec;
    graph.insert(graph.begin(), n + 1, vec);
    rgraph.insert(rgraph.begin(), n + 1, vec);
    std::vector<int> portals(n + 1, 0);
    std::vector<int> in_portal(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int portal;
        std::cin >> portal;
        in_portal[portal]++;
        portals[i] = portal;
        graph[i].push_back(portal);
        rgraph[portal].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        topological(i);
    }

    int counter = 1;
    while (!stack.empty()) {
        int x = stack.top();
        counter++;
        dfs(x, counter);
    }

    std::vector<int> scc_size(counter + 1, 0);
    for (int i = 1; i <= n; i++) {
        scc_size[scc[i]]++;
    }

    std::vector<int> scc_size_node(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        scc_size_node[i] = scc_size[scc[i]];
    }

    for (int i = 1; i <= n; i++) {
        if (scc_size_node[i] == 1) {
            if (portals[i] != i) {
                scc_size_node[i] = 0;
            }
        }
    }

    std::vector<int> starting_points;
    for (int i = 1; i <= n; i++) {
        if (in_portal[i] == 0) {
            starting_points.push_back(i);
        }
    }

    


    


    return 0;
}