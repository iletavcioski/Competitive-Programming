#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::string a;
    std::string b; 

    std::cin >> a >> b; 

    std::vector<int> vis(26, -1);
    std::vector<std::pair<char, char> > res;
    bool notok = false;
    for (int i = 0; i < a.size(); i++) {
        if (vis[a[i] - 'a'] == -1 and vis[b[i] - 'a'] == -1) {
            vis[a[i] - 'a'] = b[i] - 'a';
            vis[b[i] - 'a'] = a[i] - 'a';
            if (a[i] != b[i])
                res.push_back({a[i], b[i]});
        } else if (vis[a[i] - 'a'] == -1 and vis[b[i] - 'a'] != -1) {
            notok = true;
            break;
        } else if (vis[a[i] - 'a'] != -1 and vis[b[i] - 'a'] == -1) {
            notok = true;
            break;
        } else if (vis[a[i] - 'a'] != b[i] - 'a' or vis[b[i] - 'a'] != a[i] - 'a') {
            notok = true;
            break;
        }
    }
    if (notok) {
        std::cout << -1 << "\n";
    } else {
        std::cout << res.size() << "\n";
        for (auto p : res) {
            std::cout << p.first << " " << p.second << "\n";
        }
    }


    return 0;
}