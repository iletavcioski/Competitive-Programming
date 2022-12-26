#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;

        std::vector<int> v(26, -1);

        std::vector<std::pair<int, std::pair<int, int> > > vec;

        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a'] == -1) {
                v[s[i] - 'a'] = i;
            } else {
                vec.push_back({i - v[s[i] - 'a'] - 1, {v[s[i] - 'a'], i}});
                v[s[i] - 'a'] = i;
            }
        }

        std::sort(vec.begin(), vec.end());
        std::vector<int> vis(s.size() + 1, 0);
        int res = 0;
        std::set<std::pair<int, int> > set;
        for (int i = 0; i < vec.size(); i++) {
            int a = vec[i].second.first;
            int b = vec[i].second.second;
            if (vis[a] || vis[b]) {
                continue;
            }

            if (set.size() == 0) {
                res += 2;
                vis[a] = true;
                vis[b] = true;
                set.insert({a, 0});
                set.insert({b, 1});
                continue;

            }

            auto itl = set.lower_bound({a, 0});
            auto itr = set.lower_bound({b, 1});
            if (itl == itr) {
                if (itl != set.end() && itl != set.begin()) {
                    auto itl1 = itl;
                    itl1--;
                    auto itr1 = itr;
                    //itr1++;
                    auto parl = *itl1;
                    auto parr = *itr1;
                    if (parl.second == 1 && parr.second == 0) {
                        res += 2;
                        vis[a] = true;
                        vis[b] = true;
                        set.insert({a, 0});
                        set.insert({b, 1});
                    }
                } else {
                        res += 2;
                        vis[a] = true;
                        vis[b] = true;
                        set.insert({a, 0});
                        set.insert({b, 1});
                }

            }
        }

        std::cout << s.size() - res << "\n";

    }

    /*
2
aaababbb
oaoaaaoo

     */
    return 0;
}