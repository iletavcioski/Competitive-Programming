#include <iostream>
#include <set>
#include <map>

#define maxi 1e9

int n;
int segtree[1000000];
int new_values[200001];
int old_values[200001];
std::map<int, int> map;

int pos;
int I, J;
int value;

void update(int l, int r, int p) {
    if (l == r) {
        segtree[p] = value;
        return;
    }

    if (l > pos || r < pos) {
        return;
    }

    update(l, (l + r) / 2, 2 * p);
    update((l + r) / 2 + 1, r, 2 * p + 1);
    segtree[p] = std::min(segtree[2 * p], segtree[2 * p + 1]);
    return;
}

int query(int l, int r, int p) {
    if (l > J || r < I) {
        return maxi;
    }

    if (l >= I && r <= J) {
        return segtree[p];
    }

    return std::min(query(l, (l + r) / 2, 2 * p), query((l + r) / 2 + 1, r, 2 * p + 1));
}

void convert() {
    std::set<int> set;
    for (int i = 0; i < n; i++) {
        set.insert(old_values[i]);
    }
    int cnt = 1;
    
    for (int x : set) {
        map[x] = cnt;
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        new_values[i] = map[old_values[i]];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> old_values[i];
    }

    

    return 0;
}