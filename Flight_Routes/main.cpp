#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node {
    int x;
    long long val;
};

bool operator <(const node &x, const node &y) {
    return x.val > y.val;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int, int> > > graph;
    std::vector<std::pair<int, int> > vec;
    graph.insert(graph.begin(), n + 1, vec);
    std::vector<int> vis(n + 1, k);
    std::vector<long long> dp(n + 1, 1e18);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    std::priority_queue<node> pq;

    pq.push({1, 0});
    dp[1] = 0;
    std::vector<long long> res;
    while (!pq.empty()) {
        node mom = pq.top();
        //std::cout << mom.x << "\n";
        pq.pop();
        if (!vis[mom.x]) {
            continue;
        }
        vis[mom.x]--;

        if (mom.x == n) {
            res.push_back(mom.val);
        }

        for (auto &p : graph[mom.x]) {
            pq.push({p.first, mom.val + p.second});
        }
    }

    std::sort(res.begin(), res.end());
    for (int i = 0; i < k; i++) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}