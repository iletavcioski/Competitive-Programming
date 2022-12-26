#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v;
    v.resize(n);

    std::vector<int> vis(1000001, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int max = 0;

    for (int i = 0; i < n; i++) {
        int next = 0;
        int mom_max = 0;
        int sec = 1;
        bool cc = false;
        for (int j = i + 1; j < n; j++) {
            if (v[j] != v[i]) {
                if (vis[v[j]] == next) {
                    vis[v[j]]++;
                    cc = true;
                    mom_max = std::max(mom_max, vis[v[j]]);
                }
            } else {
                next++;
                if (cc) {
                    cc = false;
                    sec++;
                }
                
            }
        }
        sec += mom_max;
        max = std::max(max, std::max(sec, next));
        for (int j = 0; j < n; j++) {
            vis[v[j]] = 0;
        }
    }
    std::cout << max << "\n";
    return 0;
}