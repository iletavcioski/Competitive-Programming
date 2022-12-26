#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

int m;
bool impossible = false;

std::vector<int> graph[200002];
std::vector<int> rgraph[200002];
std::vector<bool> visited(200002, false);
std::stack<int> stack;
std::vector<int> scc(200002, 0);
std::stack<int> q;
std::vector<bool> solution(100001, false);
std::vector<int> visited_final(100001, 0);
std::vector<bool> check_contradiction(100001, false);
std::vector<int> check(100001, 0);
std::vector<int> visited_pass(200002, 0);

void topological_sort(int x) {
    if (visited[x]) {
        return;
    }
    
    visited[x] = true;
    for (int next : graph[x]) {
        topological_sort(next);
    }

    stack.push(x);
    return;
}

void dfs(int x, int counter) {
    if (scc[x]) {
        return;
    }

    scc[x] = counter;
    for (int next : rgraph[x]) {
        dfs(next, counter);
    }
    return;
}

void find_solution(int x, int component) {
    int node = x;
    bool res = false;
    if (x > m) {
        node -= m;
        res = true;
    }
    if (!visited_final[node]) {
        visited_final[node] = component;
        solution[node] = res;
    } 

    if (check[node] != component) {
        check[node] = component;
        check_contradiction[node] = res;
    } else if (check[node] == component && check_contradiction[node] != res) {
        impossible = true;
    }

    if (visited_pass[x]) {
        return;
    }
    visited_pass[x] = component;

    for (int next : graph[x]) {
        if (scc[next] == component) {
            find_solution(next, component);
        }
    }
} 

void create_scc() {
    int cnt = 1;
    while (!stack.empty()) {
        int top = stack.top();
        stack.pop();
        
        if (!scc[top]) {
            q.push(top);
            dfs(top, cnt);
            cnt += 1;
        }
    }
}

void scc_search() {
    while (!q.empty()) {
        int top = q.top();
        q.pop();
        find_solution(top, scc[top]);
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        char c1, c2;
        int topping1, topping2;
        std::cin >> c1 >> topping1 >> c2 >> topping2;
        
        bool b1 = (c1 == '+');
        bool b2 = (c2 == '+');

        int from1 = topping1, to1 = topping2;
        if (!b1) {
            from1 += m;
        }

        if (b2) {
            to1 += m; 
        }
        graph[from1].push_back(to1);
        rgraph[to1].push_back(from1);
        
        from1 = topping2, to1 = topping1;
        if (!b2) {
            from1 += m;
        }

        if (b1) {
            to1 += m; 
        }

        graph[from1].push_back(to1);
        rgraph[to1].push_back(from1);
        
    }

    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) {
            topological_sort(i);
        }
    }

    create_scc();
    scc_search();

    if (impossible) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    std::string result = "";
    for (int i = 1; i <= m; i++) {
        if (i > 1) {
            std::cout << ' ';
        }
        if (solution[i]) {
            std::cout << '+';
        } else {
            std::cout << '-';
        }
    }


    return 0;
}