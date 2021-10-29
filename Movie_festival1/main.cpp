#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int> > mov;
    std::set<int> set;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        mov.emplace_back(a, b);
        set.insert(a);
        set.insert(b);
    }
    int count = 1;
    std::map<int, int> map;
    for (int num : set) {
        map[num] = count;
        count++;
    }
    std::vector<std::vector<int>> graf;
    std::vector<int> vec;
    graf.insert(graf.begin(), count + 1, vec);
    for (auto& [l, r] : mov) {
        l = map[l];
        r = map[r];
        graf[l].emplace_back(r);
    }

    std::vector<int> dp(count + 1, 0);
    for (int i = 1; i <= count; i++) {
        dp[i] = std::max(dp[i - 1], dp[i]);
        for (auto num : graf[i]) {
            dp[num] = std::max(dp[num], dp[i] + 1);
        }
    }
    std::cout << dp[count] << std::endl;
    return 0;
}
