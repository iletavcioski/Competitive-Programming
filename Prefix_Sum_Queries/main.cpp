#include <iostream>

int ar[200002];

struct state {
    long long all;
    long long prefix;
};

state st[800008];

void build(int l, int r, int p) {
    if (l == r) {
        st[p] = {ar[l], std::max(0, ar[r])};
        return;
    }

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);

    state left = st[2 * p];
    state right = st[2 * p + 1];
    state newn = {0, 0};
    newn.all = left.all + right.all;
    newn.prefix = std::max(left.prefix, left.all + right.prefix);
    st[p] = newn;
    return;
}

void update(int l, int r, int p, int pos, int val) {
    if (l == r && l == pos) {
        st[p] = {val, std::max(0LL, (long long)val)};
        return;
    }

    if (l > pos || r < pos) {
        return;
    }

    update(l, (l + r) / 2, 2 * p, pos, val);
    update((l + r) / 2 + 1, r, 2 * p + 1, pos, val);

    state left = st[2 * p];
    state right = st[2 * p + 1];
    state newn = {0, 0};
    newn.all = left.all + right.all;
    newn.prefix = std::max(left.prefix, left.all + right.prefix);
    st[p] = newn;
    return;
}

state query(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) {
        return st[p];
    }

    if (l > j || r < i) {
        return {0, 0};
    }

    state left = query(l, (l + r) / 2, 2 * p, i, j);
    state right = query((l + r) / 2 + 1, r, 2 * p + 1, i, j);
    state newn = {0, 0};
    newn.all = left.all + right.all;
    newn.prefix = std::max(left.prefix, left.all + right.prefix);
    return newn;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }

    build(0, n - 1, 1);

    for (int i = 0; i < q; i++) {
        int a, x, y;
        std::cin >> a >> x >> y;

        if (a == 1) {
            update(0, n - 1, 1, x - 1, y);
        } else {
            std::cout << query(0, n - 1, 1, x - 1, y - 1).prefix << '\n';
        }
    }
    return 0;
}