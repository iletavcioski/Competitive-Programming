#include <bits/stdc++.h>

typedef long long ll;
std::vector<std::vector<int> > tree;
std::vector<ll> vals;

ll res = 0;
ll dfs(int x) {
    if (tree[x].size() == 0) {
        return vals[x];
    }

    std::vector<ll> v;
    ll sum = 0;
    for (int next : tree[x]) {
        ll num = dfs(next);
        if (x == 0) {
            res += num;
        }
        sum += num;
        v.push_back(num);
    }

    if (x == 0) {
        return -1;
    }
    ll max = 0;
    ll ret = -1;
    ll which = 0;
    for (int i = 0; i < v.size(); i++) {
        sum -= v[i];
        if (sum + std::max(v[i], vals[x]) > max) {
            max = sum + std::max(v[i], vals[x]);
            ret = std::max(v[i], vals[x]);
            which = v[i];
        } else if (sum + std::max(v[i], vals[x]) == max) {
            if (std::max(v[i], vals[x]) > ret) {
                ret = std::max(v[i], vals[x]);
                which = v[i];
            }
        }
        sum += v[i];
    }
    res += (sum - which);
    return ret;
}

int main() {

    int t;
    std::cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        std::cin >> n;

        std::vector<int> vec;
        tree.clear();
        tree.insert(tree.begin(), n + 1, vec);
        vals.clear();
        res = 0;
        vals.push_back(0);
        for (int i = 0; i < n; i++) {
            ll num;
            std::cin >> num;
            vals.push_back(num);
        }

        for (int i = 1; i <= n; i++) {
            int num;
            std::cin >> num;
            tree[num].push_back(i);
        }
        dfs(0);
        std::cout << "Case #" << tt << ": " << res << std::endl;
    }
    return 0;
}