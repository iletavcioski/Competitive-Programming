#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph((1 << (n - 1)));

    if (n == 1) {
        std::cout << "10" << "\n";
        return 0;
    }
    
    for (int i = 0; i < (1 << (n - 1)); i++) {
        int next = (i << 1) % (1 << (n - 1));
        graph[i].push_back(next);
        graph[i].push_back(next | 1);
    }

    std::stack<int> todo;
    todo.push(0);
    std::vector<int> result;
    std::vector<bool> visited((1<< n), false);
    while (!todo.empty()) {
        int tops = todo.top();
        if (graph[tops].empty()) {
           
            result.push_back(tops & 1);
                
            todo.pop();
        } else {
            todo.push(graph[tops].back());
            graph[tops].pop_back();
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
    }
    for (int i = 0; i < n - 2; i++) {
        std::cout << "0";
    }
    std::cout << std::endl;
    
    return 0;
}