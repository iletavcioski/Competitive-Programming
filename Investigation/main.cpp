#include <iostream>
#include <queue>
#include <vector>

struct node {
    int x;
    long long val;
};

bool operator <(const node &x, const node &y) {
    return x.val > y.val;
}
const long long mod = 1000000007;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, long long> > > graph;
    std::vector<std::pair<int, long long> > vec;
    graph.insert(graph.begin(), n + 1, vec);
    std::vector<int> vis(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
    }


    std::priority_queue<node> pq;

    std::vector<long long> distances(n, 1e18);
    std::vector<int> max_length(n, 0);
    std::vector<int> min_length(n, 1e9);
    std::vector<long long> dp(n, 0);
    max_length[0] = 0;
    min_length[0] = 0;
    distances[0] = 0;
    dp[0] = 1;

    pq.push({0, 0});

    while (!pq.empty()) {
        node topi = pq.top();
        pq.pop();
        if (vis[topi.x]) {
            continue;
        }
        vis[topi.x] = 1;
        //std::cout << topi.x << " " << distances[topi.x] << " " << dp[topi.x] << " " << min_length[topi.x] << " " << max_length[topi.x] << "\n";
        for (auto p : graph[topi.x]) {
            if (!vis[p.first] and distances[p.first] > topi.val + p.second) {
                distances[p.first] = topi.val + p.second;
                max_length[p.first] = max_length[topi.x] + 1;
                min_length[p.first] = min_length[topi.x] + 1;
                dp[p.first] = dp[topi.x];
                pq.push({p.first, topi.val + p.second});
            } else if (distances[p.first] == topi.val + p.second) {
                distances[p.first] = topi.val + p.second;
                max_length[p.first] = std::max(max_length[p.first], max_length[topi.x] + 1);
                min_length[p.first] = std::min(min_length[p.first], min_length[topi.x] + 1);
                dp[p.first] += dp[topi.x];
                dp[p.first] %= mod;
                pq.push({p.first, topi.val + p.second});
            }
        }
    }

    std::cout << distances[n - 1] << " " << dp[n - 1] << " " << min_length[n - 1] << " " << max_length[n - 1] << "\n";
    return 0;
}