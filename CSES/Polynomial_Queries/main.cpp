#include <iostream>
#include <vector>

std::vector<long long> arr;

struct state {
    long long sum;
    long long lazy;
    long long cnt;
};
class SegTree {


public:

    std::vector<state> st;

    SegTree(int n) {
        arr.resize(n);
        for (int i = 0; i < 4 * n; i++) {
            st.push_back({0, 0, 0});
        }
    }

    void merge(int p, int l, int r) {
        st[p].sum = st[l].sum + st[r].sum;
        return;
    }

    void lazy_propagation(long long l, long long r, int p) {
        //st[p].sum += ((r - l + 1) * st[p].lazy + (st[p].cnt * (r - l) * (r - l + 1) / 2));
        if (st[p].cnt > 0) {
            if (l != r) {
                st[2 * p].lazy += st[p].lazy;
                st[2 * p + 1].lazy += ((((l + r) / 2 + 1 - l) * st[p].cnt) + st[p].lazy);
                st[2 * p].cnt += st[p].cnt;
                st[2 * p + 1].cnt += st[p].cnt;
            }
            st[p].sum += ((r - l + 1) * st[p].lazy + (st[p].cnt * (r - l) * (r - l + 1) / 2));
            st[p].lazy = 0;
            st[p].cnt = 0;
        }
    }

    void build(int l, int r, int p) {
        if (l == r) {
            st[p].sum = arr[l];
            return;
        }

        build(l, (l + r) / 2, 2 * p);
        build((l + r) / 2 + 1, r, 2 * p + 1);
        merge(p, 2 * p, 2 * p + 1);
        return;
    }

    void update_1(long long l, long long r, int p, int i, int j, long long val) {
        lazy_propagation(l, r, p);
        if (l >= i && r <= j) {
            val += l-i;
            st[p].sum += ((val * (r - l + 1)) + ((r - l) * (r - l + 1) / 2));
            st[p].cnt = 0;
            if (l != r) {
                st[2 * p].lazy += val;
                st[2 * p + 1].lazy += (val + ((l + r) / 2 + 1 - l));
                st[2 * p].cnt += 1;
                st[2 * p + 1].cnt += 1;
            }
            return;
        }

        if (l > j || r < i) {
            return;
        }


        update_1(l, (l + r) / 2, 2 * p, i, j, val);
        update_1((l + r) / 2 + 1, r, 2 * p + 1, i, j, val);
        merge(p, 2 * p, 2 * p + 1);
        return;
    }



    long long query(long long l, long long r, int p, int i, int j) {
        lazy_propagation(l, r, p);
        if (l >= i && r <= j) {

            return st[p].sum;
        }

        if (l > j || r < i) {
            return 0;
        }


        long long left = query(l, (l + r) / 2, 2 * p, i, j);
        long long right = query((l + r) / 2 + 1, r, 2 * p + 1, i, j);
        merge(p, 2 * p, 2 * p + 1);
        return left + right;
    }

    ~SegTree() {}

};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    SegTree *seg = new SegTree(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    seg->build(0, n - 1, 1);

    for (int i = 0; i < q; i++) {
        int up;
        std::cin >> up;
        if (up == 1) {
            int x, y;
            long long val;
            std::cin >> x >> y;
            val = 1;
            x--;
            y--;
            seg->update_1(0, n - 1, 1, x, y, val);
        } else {
            int x, y;
            std::cin >> x >> y;
            x--;
            y--;
            std::cout << seg->query(0, n - 1, 1, x, y) << '\n';
        }
    }
    seg->~SegTree();
    return 0;
}

/*
5 2
1 1 1 1 1
1 1 5
2 3 4
*/