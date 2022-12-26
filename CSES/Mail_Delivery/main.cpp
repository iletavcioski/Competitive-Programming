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
        graph[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
 
    bool no = false;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2) {
            no = true;
        }
    }
 
    if (no) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::stack<int> stack;
        stack.push(1);
        while(!stack.empty()) {
            int top = stack.top();

            if (graph[top].empty()) {
                eulerian.push_back(top);
                stack.pop();
            } else {
                edges--;
                int next = *graph[top].begin();
                graph[top].erase(next);
                graph[next].erase(top);
                stack.push(next);
            }
        }
        if (edges != 0) {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
        
        for (int i = eulerian.size() - 1; i >= 0; i--) {
            printf("%d ", eulerian[i]);
        }
    }
}