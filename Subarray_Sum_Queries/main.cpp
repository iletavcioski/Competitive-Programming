#include <iostream>

struct state {
    long long prefix;
    long long sufix;
    long long all;
    long long max_sub;
};

state st[800008];
int ar[200002];

void build(int l, int r, int p) {
    if (l == r) {
        st[p] = {std::max(0, ar[l]), std::max(0, ar[l]), ar[l], std::max(0, ar[l])};
        return;
    }

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);

    state left = st[2 * p];
    state right = st[2 * p + 1];
    state _new;
    _new.all = left.all + right.all;
    _new.prefix = std::max(left.prefix, left.all + right.prefix);
    _new.sufix = std::max(right.sufix, left.sufix + right.all);
    _new.max_sub = std::max(_new.prefix, std::max(right.max_sub, std::max(left.max_sub, left.sufix + right.prefix)));
    _new.max_sub = std::max(_new.max_sub, std::max(_new.sufix, _new.all));
    st[p] = _new;
}

void update(int l, int r, int p, int pos, int val) {
    if (l == r && l == pos) {
        st[p] = {std::max(0, val), std::max(0, val), val, std::max(0, val)};
        return; 
    }

    if (l > pos || r < pos) {
        return;
    }

    update(l, (l + r) / 2, 2 * p, pos, val);
    update((l + r) / 2 + 1, r, 2 * p + 1, pos, val);

    state left = st[2 * p];
    state right = st[2 * p + 1];
    state _new;
    _new.all = left.all + right.all;
    _new.prefix = std::max(left.prefix, left.all + right.prefix);
    _new.sufix = std::max(right.sufix, left.sufix + right.all);
    _new.max_sub = std::max(_new.prefix, std::max(right.max_sub, std::max(left.max_sub, left.sufix + right.prefix)));
    _new.max_sub = std::max(_new.max_sub, std::max(_new.sufix, _new.all));
    st[p] = _new;
}

state query(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) {
        return st[p];
    }

    if (l > j || r < i) {
        return {0, 0, 0, 0};
    }

    state left = query(l, (l + r) / 2, 2 * p, i, j);
    state right = query((l + r) / 2 + 1, r, 2 * p + 1, i, j);
    state _new;
    _new.all = left.all + right.all;
    _new.prefix = std::max(left.prefix, left.all + right.prefix);
    _new.sufix = std::max(right.sufix, left.sufix + right.all);
    _new.max_sub = std::max(_new.prefix, std::max(right.max_sub, std::max(left.max_sub, left.sufix + right.prefix)));
    _new.max_sub = std::max(_new.max_sub, std::max(_new.sufix, _new.all));
    return st[p];
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
        int a, b;
        std::cin >> a >> b;
        a--;
        update(0, n - 1, 1, a, b);
        std::cout << query(0, n - 1, 1, 0, n - 1).max_sub << "\n";
    }
}