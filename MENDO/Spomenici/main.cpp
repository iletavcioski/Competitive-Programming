#include <iostream>
#include <vector>


std::vector<std::vector<int> > tree;
std::vector<int> nearest(100001, 10000001);
std::vector<int> depth()
void dfs(int x, int prev, int dist) {
    nearest[x] = std::min(nearest[x], dist);
    for (int next : tree[x]) {
        if (next != prev) {
            dfs(next, x, dist + 1);
        }
    }
}

void recursion(int x) {

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<int> vec;
    tree.insert(tree.begin(), n + 1, vec);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfs(2, 0, 0);


    return 0;
}