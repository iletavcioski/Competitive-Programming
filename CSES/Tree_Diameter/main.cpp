#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> tree[200002];
std::vector<std::pair<long long, int> > dp1(200002, {0, -1});
std::vector<std::pair<long long, int> > dp2(200002, {0, -1});
std::vector<long long> dp(200002, 0);

void dfs1(int x, int prev) {
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        dfs1(next, x);

        std::pair<long long, int> p = {dp1[next].first + 1, next};
        if (p.first > dp1[x].first) {
            dp2[x] = dp1[x];
            dp1[x] = p;
        } else if (p.first > dp2[x].first) {
            dp2[x] = p;
        }
    }
}

void dfs2(int x, int prev, long long till_now) {
    dp[x] = till_now;
    for (int next : tree[x]) {
        if (next == prev) {
            continue;
        }

        std::pair<long long, int> p = dp1[x];
        if (dp1[x].second == next) {
            p = dp2[x];
        }
        dfs2(next, x, std::max(till_now, p.first) + 1);
    }
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

    dfs1(1, 0);
    dfs2(1, 0, 0);

    long long max = 0;

    for (int i = 1; i <= n; i++) {
        max = std::max(max, std::max(dp1[i].first + dp2[i].first, dp1[i].first + dp[i]));
    }
    std::cout << max << std::endl;
    return 0;
}