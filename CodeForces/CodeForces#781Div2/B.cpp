#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

typedef long long ll;

const ll mod = 998244353;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    

    while (t--) {
        int n;
        std::cin >> n;
        std::map<int, int> map;
        int max = 0;
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            map[num]++;
            max = std::max(map[num], max);
        }
        int _new = ((n - max) / max);
        long long poc = max;
        int cnt = 0;
        while (poc < (ll)n) {
            poc += (poc);
            cnt++;
            if (poc == (ll)n) {
                break;
            }
        }
        _new = cnt;
        std::cout << _new + (n - max) << "\n";
    }
    return 0;
}
