#include <iostream>
#include <queue>

struct node {
    int x;
    long long c;
};

bool operator<(const node &a, const node &b) {
    return a.c > b.c;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int> > > graph;
    std::vector<std::pair<int, int> > vec;
    graph.insert(graph.begin(), n, vec);  

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;

        a--;
        b--;
        graph[a].push_back({b, c});

    }

    std::vector<long long> dist(n, 1e18);
    dist[0] = 0;
    std::priority_queue<node> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        node g = pq.top();
        pq.pop();
        if (g.c > dist[g.x]) {
            continue;
        }
        for (auto &p : graph[g.x]) {
            if (dist[p.first] > g.c + p.second) {
                dist[p.first] = g.c + p.second;
                pq.push({p.first, g.c + p.second});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << dist[i] << " ";
    }
    std::cout << "\n";

    return 0;
}