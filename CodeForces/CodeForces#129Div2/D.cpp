#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::map<int, int> mapl;
    std::map<int, int> mapr;

    int n;
    std::cin >> n;
    std::set<int> set;

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        mapl[a]++;
        if (a != b)
            mapr[b]++;
        set.insert(a);
        set.insert(b);
    }

    int half = (n + 1) / 2;
    int min = 1e9;

    for (int x : set) {
        int cnt = mapl[x];
        int cntr = mapr[x];
        if ((cnt + cntr) >= half) {
            int left = cnt + cntr - half;
            min = std::min(min, std::max(0, cntr - left));
        }
    }

    if (min == 1e9) {
        std::cout << -1 << "\n";
    } else {
        std::cout << min << "\n";
    }

    return 0;
}