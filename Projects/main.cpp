#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    
    std::vector<std::vector<std::pair<int, int> > > ends;
   
    std::set<int> set;
    std::map<int, int> map;
    std::array<int, 3> proj[n];

    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        proj[i] = {a, b, c};
        set.insert(a);
        set.insert(b);
    }

    int cnt = 0;
    for (int x : set) {
        map[x] = ++cnt;
    }

    std::vector<std::pair<int, int> > vec;
    ends.insert(ends.begin(), cnt + 1, vec);
    for (int i = 0; i < n; i++) {
        ends[map[proj[i][0]]].push_back({map[proj[i][1]], proj[i][2]});
    }
    std::vector<long long> dp(cnt + 1, 0);
    for (int i = 1; i <= cnt; i++) {
        dp[i] = std::max(dp[i], dp[i - 1]);
        for (int j = 0; j < ends[i].size(); j++) {
            dp[ends[i][j].first] = std::max(dp[i - 1] + ends[i][j].second, dp[ends[i][j].first]);
        }
    }

    std::cout << dp[cnt] << std::endl;
    return 0;
}