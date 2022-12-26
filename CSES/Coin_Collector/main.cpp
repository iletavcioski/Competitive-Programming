#include <iostream>
#include <vector>
#include <stack>
#include <set>

std::vector<std::vector<int> > graph;
std::vector<std::vector<int> > rgraph;
std::vector<std::vector<int> > newGraph;
std::vector<long long> values(1000001, 0);
std::vector<long long> newValues(100001, 0);
std::vector<bool> visited(100001, false);
std::stack<int> stack;
std::vector<int> scc(100001, 0);
std::vector<long long> dp(1000001, 0);

void topological(int x) {
    if (visited[x])
        return;
    visited[x] = true;
    for (int next : graph[x]) {
        topological(next);
    }
    stack.push(x);
    return;
}

void dfs(int x, int counter) {
    if (scc[x])
        return;
    scc[x] = counter;
    for (int next : rgraph[x]) {
        dfs(next, counter);
    }
    return;
}

void create_newGraph(int n, int num_scc) {
    std::vector<int> vec;
    newGraph.insert(newGraph.begin(), num_scc + 1, vec);
    std::set<std::pair<int, int> > set;

    for (int i = 1; i <= n; i++) {
        for (int neigh : graph[i]) {
            if (scc[i] == scc[neigh]) {
                continue;
            }
            set.insert({scc[i], scc[neigh]});
        }
    }

    for (auto p : set) {
        newGraph[p.first].push_back(p.second);
    }
    return;
}

void create_newValues(int n) {
    for (int i = 1; i <= n; i++) {
        newValues[scc[i]] += values[i];
    }
}

long long tree_dfs(int x) {
    if (dp[x]) {
        return dp[x];
    }
    dp[x] = newValues[x];
    long long max = 0;
    for (int next : newGraph[x]) {
        max = std::max(max, tree_dfs(next));
    }
    dp[x] += max;
    return dp[x];
}

long long calculateMax() {
    long long max = 0;
    for (long long x : dp) {
        max = std::max(max, x);
    }
    return max;
}

int createSCC() {
    int counter = 0;
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        dfs(node, ++counter);
    }
    return counter;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<int> vec;
    graph.insert(graph.begin(), n + 1, vec);
    rgraph.insert(rgraph.begin(), n + 1, vec);

    for (int i = 1; i <= n; i++) {
        std::cin >> values[i];
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        topological(i);
    }

    int num_scc = createSCC();
    create_newGraph(n, num_scc);
    create_newValues(n);
    for (int i = 1; i <= n; i++) {
        tree_dfs(i);
    }
     /*
    for (int i = 1; i <= n; i++) {
        std::cout << i << " " << scc[i] << std::endl;
    }
    */
    std::cout << calculateMax() << std::endl;
    return 0;
}