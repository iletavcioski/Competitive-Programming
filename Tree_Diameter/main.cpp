#include <iostream>
#include <vector>

std::vector<int> tree[200002];


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    
    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    return 0;
}