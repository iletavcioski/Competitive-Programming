#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

std::set<int> graph[100001];
std::vector<int> vis(100001, 0);
std::vector<bool> vis_edge(200002, false);
std::vector<int> eulerian;
int edges = 0;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;
    edges = m;
    std::vector<int> deg(n + 1, 0);
    std::vector<std::pair<int, int> > vec;

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;

        graph[a].insert(b);
        deg[a]--;
        deg[b]++;
    }

    bool no = false;
    int neparni = 0;
    int first = -1;
    int second = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == -1) {
            neparni++;
            first = i;
        } else if (deg[i] == 1) {
            second = i;
            neparni++;
        } else if (deg[i] != 0) {
            no = true;
        }
    }

    if (neparni == 1 || neparni > 2 || no) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::stack<int> stack;
        if (first != 1 or second != n) {
            std::cout << "IMPOSSIBLE" << std::endl;
            return 0;
        }
        else {
            stack.push(first);
        }
        while(!stack.empty()) {
            int top = stack.top();

            if (graph[top].empty()) {
                eulerian.push_back(top);
                stack.pop();
            } else {
                edges--;
                int next = *graph[top].begin();
                graph[top].erase(next);
                stack.push(next);
            }
        }
        if (edges != 0) {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }

        if (eulerian[0] != n) {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
        int end = 0;
        if (first == -1) end = 1;
        for (int i = eulerian.size() - 1; i >= 0; i--) {
            printf("%d ", eulerian[i]);
        }
    }
}