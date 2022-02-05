#include <iostream>
#include <set>


int st[1000000];
int stin[1000000];
int ar[200001];

void build(int l, int r, int p) {
    if (l == r) {
        st[p] = ar[l];
        stin[p] = l;
        return;
    }

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);
    if (st[2 * p] > st[2 * p + 1]) {
        st[p] = st[2 * p];
        stin[p] = stin[2 * p + 1];
    } else if (st[2 * p] < st[2 * p + 1]) {
        st[p] = st[2 * p + 1];
        stin[p] = stin[2 * p + 1];
    } else if (st[2 * p] == st[2 * p + 1]) {
        st[p] = st[2 * p];
        if (stin[2 * p] > st[2 * p + 1]) {
            stin[p] = stin[2 * p];
        } else {
            stin[p] = stin[2 * p + 1];
        }
    }
}

void update(int l, int r, int i, int j, int val, int p) {
    if (l >= i && r <= j) {
        st[p] = val;
        return;
    }

    if (l > j || r < i) {
        return;
    }

    update(l, (l + r) / 2, i, j, val, 2 * p);
    update((l + r) / 2 + 1, r, i, j, val, 2 * p + 1);
    if (st[2 * p] > st[2 * p + 1]) {
        st[p] = st[2 * p];
        stin[p] = stin[2 * p + 1];
    } else if (st[2 * p] < st[2 * p + 1]) {
        st[p] = st[2 * p + 1];
        stin[p] = stin[2 * p + 1];
    } else if (st[2 * p] == st[2 * p + 1]) {
        st[p] = st[2 * p];
        if (stin[2 * p] > st[2 * p + 1]) {
            stin[p] = stin[2 * p];
        } else {
            stin[p] = stin[2 * p + 1];
        }
    }
}

std::pair<int, int> query(int l, int r, int i, int j, int p) {
    if (l >= i && r <= j) {
        return {st[p], stin[p]};
    }

    if (l > j || r < i) {
        return {-1, -1};
    }

    auto p1 = query(l, (l + r) / 2, i, j, 2 * p);
    auto p2 = query((l + r) / 2 + 1, r, i, j, 2 * p + 1);

    if (p1.first > p2.first) {
        return p1;
    } else if (p2.first > p1.first) {
        return p2;
    } else {
        return {p1.first, std::max(p1.second, p2.second)};
    }
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
        int num;
        std::cin >> num;

        int l = 0, r = n - 1;
        int min = n;
        int idx = -1;
        int val = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            auto p = query(0, n - 1, 0, mid, 1);
            if (p.first >= num) {
                min = std::min(min, mid);
                idx = p.second;
                val = p.first - num;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        if (min == n) {
            std::cout << 0 << " ";
        } else {
            update(0, n - 1, idx, idx, val, 1);
            std::cout << min + 1 << " ";
        }
    }
    return 0;
}