#include <iostream>
#include <vector>
#include <queue>

std::vector<int> parent(100001, -1);

int find(int x) {
    if (parent[x] == -1) {
        return x;
    } else {
        return find(parent[x]);
    }
}

void set_parent(int x, int _parent) {
    if (parent[x] == -1) {
        return;
    } else if (x != _parent) {
        int next = parent[x];
        parent[x] = _parent;
        return set_parent(next, _parent);
    }
} 

struct edge {
    int a;
    int b;
    long long val;
};

bool operator <(const edge &x, const edge &y) {
    return x.val > y.val;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::priority_queue<edge> pq;

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    long long res = 0;
    int num = n;
    while (!pq.empty()) {
        edge e = pq.top();
        pq.pop();

        int a = e.a;
        int b = e.b;
        int parent_a = find(a);
        int parent_b = find(b);

        //std::cout << parent_a << " " << parent_b << "\n";
        if (parent_a == parent_b) {
            continue;
        }

        if (parent_a != parent_b) {
            num--;
            int new_parent = std::min(parent_a, parent_b);
            if (new_parent != parent_a) {
                parent[parent_a] = new_parent;
            } else {
                parent[parent_b] = new_parent;
            }
            set_parent(a, new_parent);
            set_parent(b, new_parent);
            res += e.val;
        }
    }

    if (num > 1) {
        std::cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    std::cout << res << std::endl;
    return 0;
}