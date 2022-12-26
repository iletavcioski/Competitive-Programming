#include <bits/stdc++.h>

class SegTree {

    public:
    std::vector<long long> ar;
    std::vector<long long> st;

    SegTree(int n, std::vector<long long> _ar) {
        st.resize(4 * n);
        for (long long x : _ar) {
            ar.push_back(x);
        }
    }

    void build(int l, int r, int p) {
        if (l == r) {
            st[p] = ar[l];
            return;
        }

        build(l, (l + r) / 2, 2 * p);
        build((l + r) / 2 + 1, r, 2 * p + 1);
        st[p] = std::max(st[2 * p], st[2 * p + 1]);
    }

    long long query(int l, int r, int i, int j, int p) {
        if (l >= i && r <= j) {
            return st[p];
        }

        if (l > j || r < i) {
            return -1e18;
        }

        return std::max(query(l, (l + r) / 2, i, j, 2 * p), query((l + r) / 2 + 1, r, i, j, 2 * p + 1));

    }

    ~SegTree() {}
};

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    SegTree *segtree = new SegTree(n + 1, dp);
    segtree->build(0, n, 1);

    long long max = -1e18;
    for (int i = 0; i < n; i++) {
        if (i + a > n) {
            continue;
        }
        max = std::max(max, segtree->query(0, n, i + a, std::min(i + b, n), 1) - dp[i]);
    }
    std::cout << max << "\n";
    segtree->~SegTree();
    return 0;
}