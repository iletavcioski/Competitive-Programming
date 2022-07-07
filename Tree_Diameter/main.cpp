#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> tree[200002];
std::vector<std::pair<int, int> > dp1(200002, {0, 0});
std::vector<int> dp2(200002, 0);

void dfs1(int x, int prev) {
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        dfs1(next, x);

        std::vector<int> v{dp1[x].first, dp1[x].second, dp1[next].first, dp1[next].second};
        std::sort(v.begin(), v.end());
        dp1[x].first = v[3];
        dp1[x].second = v[2];
    }
}

void dfs2(int x, int prev) {
    
}
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