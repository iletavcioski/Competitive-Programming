#include <iostream>

int st_plusj[800008];
int st_minusj[800008];
int ar[200002];

void build(int l, int r, int p) {
    if (l == r) {
        st_plusj[p] = ar[l] + l;
        st_minusj[p] = ar[l] - l;
        return;
    } 

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);

    st_plusj[p] = std::min(st_plusj[2 * p], st_plusj[2 * p + 1]);
    st_minusj[p] = std::min(st_minusj[2 * p], st_minusj[2 * p + 1]);
    return;
}

void update(int l, int r, int p, int pos, int val) {
    if (l == r && l == pos) {
        st_plusj[p] = val + pos;
        st_minusj[p] = val - pos;
        return;
    } 

    if (l > pos || r < pos) {
        return;
    }

    update(l, (l + r) / 2, 2 * p, pos, val);
    update((l + r) / 2 + 1, r, 2 * p + 1, pos, val);

    st_plusj[p] = std::min(st_plusj[2 * p], st_plusj[2 * p + 1]);
    st_minusj[p] = std::min(st_minusj[2 * p], st_minusj[2 * p + 1]);
}

long long query_plus(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) {
        return st_plusj[p];
    }

    if (l > j || r < i) {
        return 1e18;
    }

    return std::min(query_plus(l, (l + r) / 2, 2 * p, i, j), query_plus((l + r) / 2 + 1, r, 2 * p + 1, i, j));
}

long long query_minus(int l, int r, int p, int i, int j) {
    if (l >= i && r <= j) {
        return st_minusj[p];
    }

    if (l > j || r < i) {
        return 1e18;
    }

    return std::min(query_minus(l, (l + r) / 2, 2 * p, i, j), query_minus((l + r) / 2 + 1, r, 2 * p + 1, i, j));
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
        int a;
        std::cin >> a;
        if (a == 1) {
            int x, y;
            std::cin >> x >> y;
            x--;
            update(0, n - 1, 1, x, y);
        } else {
            int x;
            std::cin >> x;
            x--;
            std::cout << std::min(query_plus(0, n - 1, 1, x, n - 1) - x, query_minus(0, n - 1, 1, 0, x) + x) << '\n';
        }
    }
    return 0;
}