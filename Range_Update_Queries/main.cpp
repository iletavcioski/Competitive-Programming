#include <iostream>


long long st[1000000];
long long ar[200000];
long long lazy[1000000];

void build(int l, int r, int p) {
    if (l == r) {
        st[p] = ar[l];
        return;
    }

    build(l, (l + r) / 2, 2 * p);
    build((l + r) / 2 + 1, r, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1];
}

void update(int l, int r, int i, int j, int val, int p) {
    
    if (l >= i && r <= j) {
        lazy[p] += val;
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        st[p] += (r - l + 1) * lazy[p];
        lazy[p] = 0;
        return;
    }

    if (l > j || r < i) {
        return;
    }

    if (lazy[p] > 0) {
        st[p] += (r - l + 1) * lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        } 
           
        
        
        lazy[p] = 0;
    }
    update(l, (l + r) / 2, i, j, val, 2 * p);
    update((l + r) / 2 + 1, r, i, j, val, 2 * p + 1);
    st[p] = st[2 * p] + st[2 * p + 1];
}

long long query(int l, int r, int i, int j, int p) {
    if (lazy[p] > 0) {
        st[p] += (r - l + 1) * lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        } 
           
        
        
        lazy[p] = 0;
    }
    
    if (l >= i && r <= j) {
        return st[p];
    }

    if (l > j || r < i) {
        return 0;
    }



    return query(l, (l + r) / 2, i, j, 2 * p) + query((l + r) / 2 + 1, r, i, j, 2 * p + 1);
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
        int t;
        std::cin >> t;
        if (t == 1) {
            int a, b, c;
            std::cin >> a >> b >> c;
            a--;
            b--;

            update(0, n - 1, a, b, c, 1);
        } else {
            int a, b;
            std::cin >> a;
            b = a;
            a--;
            b--;
            std::cout << query(0, n - 1, a, b, 1) << '\n';
        }
        
    }

}