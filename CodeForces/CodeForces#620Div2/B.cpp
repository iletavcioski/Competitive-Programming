#include <bits/stdc++.h>

typedef long long ll;

bool is_pal(std::string s) {
    std::string s1 = s;
    std::reverse(s1.begin(), s1.end());
    return s1 == s;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> v;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        v.push_back(s);
    }   

    std::vector<std::pair<std::string, std::string> > vec;
    std::vector<int> vis(n, 0);
    int max = 0;
    std::string las = "";
    for (int i = 0; i < n; i++) {
        bool cc = false;
        for (int j = i + 1; j < n; j++) {
            if (!vis[i] && !vis[j] && is_pal(v[i] + v[j])) {
                cc = true;
                vec.push_back({v[i], v[j]});
                vis[i] = true;
                vis[j] = true;
                break;
            }
        }
        if (!cc && is_pal(v[i])) {
            if (v[i].size() > max) {
                max = v[i].size();
                las = v[i];
            }
        }
    }
    std::string res = "";
    for (int i = 0; i < vec.size(); i++) {
        res += vec[i].first;
    }
    res += las;
    for (int i = vec.size() - 1; i >= 0; i--) {
        res += vec[i].second;
    }
    std::cout << res.size() << "\n";
    std::cout << res << "\n";
    return 0;
}