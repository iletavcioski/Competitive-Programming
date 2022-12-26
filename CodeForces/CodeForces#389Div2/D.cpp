#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e18 + 7;

ll hash(std::string s) {
    ll mul = 1;
    ll res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        ll let = s[i] - 'a';
        res += ((mul * let) % mod);
        res %= mod;
        mul *= 26;
        mul %= mod;
    }
    return res;
}

struct pal {
    std::string s;
    int val;
    int idx;
};

bool compare(const pal &x, const pal &y) {
    return x.val >= y.val;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, k;
    std::cin >> n >> k;

    std::vector<pal> v;

    for (int i = 0; i < n; i++) {
        std::string p;
        std::cin >> p;
        int num;
        std::cin >> num;
        v.push_back({p, num, i});
    }

    std::sort(v.begin(), v.end(), compare);
    std::vector<bool> alone(n, false);
    std::multiset<std::pair<ll, int> > set;

    ll sum = 0;
    for (auto p : v) {
        std::string r = p.s;
        std::string r1 = r;
        std::reverse(r1.begin(), r1.end());
        if (r == r1 and p.val > 0) {
            sum += p.val;
            alone[p.idx] = true;
        } else if (r != r1) {
            set.insert({hash(r), p.val});
        } else if (r == r1) {
            alone[p.idx] = true;
        }
    }


    for (auto p : v) {
        
        std::string first = p.s;
        ll fhs = hash(first);
        auto it = set.find({fhs, p.val});
        set.erase(it);
        std::reverse(first.begin(), first.end());
        ll hs = hash(first);
        auto it = set.lower_bound({hs, 100001});
        it--;

        if (hs == (*it).first and p.val + ((*it).second) > 0) {
            sum += p.val + ((*it).second);
            res.push_back({p.idx, p})
        } else if (hs == (*it).first) {
            set.erase(it);
        }

    }

    std::cout << sum << "\n";
    return 0;
}