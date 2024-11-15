#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int fenwick_tree[200001];
int fen_arr[200001];
int vec_map[200001];
int n;

void update(int i, long long val) {
    while (i <= n) {
        fenwick_tree[i] += val;
        i += (i & (-i));
    }
}

long long query_(int i) {
    long long res = 0;
    while (i >= 1) {
        res += fenwick_tree[i];
        i -= (i & (-i));
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::cin >> n;

    int q;
    std::cin >> q;
    std::vector<int> array;
    array.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> array[i];
    }

    std::vector<std::vector<std::pair<int, int> > > queries;
    std::vector<std::pair<int, int> > vec;
    queries.insert(queries.begin(), n + 1, vec);
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        queries[l].push_back({r, i});
    }

    std::vector<int> solution(q, 0);
    std::map<int, int> _map;
    for (int i = n; i >= 1; i--) {
        int last_index = -1;
        if (_map.count(array[i]) > 0) {
            last_index = _map[array[i]];
            update(last_index, -1);
        }
        _map[array[i]] = i;
        update(i, 1);

        for (auto &[right, query_index] : queries[i]) {
            solution[query_index] = query_(right);
        }
    }
    for (int i = 0; i < q; i++) {
        std::cout << solution[i] << "\n";
    }
    
    return 0;

}