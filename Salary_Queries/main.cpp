#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <algorithm>

int ar[200001];
int ft[600001];
int cnt = 0;

void update(int x, int val) {
    while (x <= cnt) {
        ft[x] += val;
        x += (-x & x);
    }
}

int query(int x) {
    int sum = 0;
    while (x) {
        sum += ft[x];
        x -= (-x & x);
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<bool, std::pair<int, int> > > que;
    std::vector<int> set;
    set.push_back(-1);
    for (int i = 1; i <= n; i++) {
        std::cin >> ar[i];
        set.push_back(ar[i]);
    }

    
    for (int i = 0; i < q; i++) {
        char ch;
        std::cin >> ch;
        if (ch == '!') {
            int a, b;
            std::cin >> a >> b;
            que.push_back({true, {a, b}});
            set.push_back(b);
        } else {
            int a, b;
            std::cin >> a >> b;
            que.push_back({false, {a, b}});
            set.push_back(b);
            set.push_back(a);
        }
    }

    std::sort(set.begin(), set.end());
    std::map<int,int> map;
    for (int i = 1; i < set.size(); i++) {
        if (set[i] != set[i - 1]) {
            map[set[i]] = ++cnt;
        }
    }

    for (int i = 1; i <= n; i++) {
        ar[i] = map[ar[i]];
        update(ar[i], 1);
    }

    for (int i = 0; i < q; i++) {
        if (que[i].first) {
            que[i].second.second = map[que[i].second.second];
            
            update(ar[que[i].second.first], -1);
            ar[que[i].second.first] = que[i].second.second;
            update(ar[que[i].second.first], 1);
        } else {
            que[i].second.first = map[que[i].second.first];
            que[i].second.second = map[que[i].second.second];
            std::cout << query(que[i].second.second) - query(que[i].second.first - 1) << '\n';
        }
    }

    return 0;
}