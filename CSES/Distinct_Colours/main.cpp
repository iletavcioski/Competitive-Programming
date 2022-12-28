#include <iostream>
#include <vector>
#include <set>

std::vector<int> tree[200002];
std::set<int> colors[200002];
std::vector<int> sol(200002, 0);

void dfs(int x, int parent) {
    for (int next : tree[x]) {
        if (next != parent) {
            dfs(next, x);
            if (colors[x].size() < colors[next].size()) {
                std::swap(colors[x], colors[next]);
            }

            for (int colour : colors[next]) {
                colors[x].insert(colour);
            }
        }
    }
    sol[x] = colors[x].size();
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int color;
        std::cin >> color;
        colors[i].insert(color);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    
    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            std::cout << " ";
        }
        std::cout << sol[i];
    }
    std::cout << std::endl;
    return 0;    
}