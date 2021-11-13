#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;

    while (t--) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        std::vector<ll> v;
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(c);
        std::sort(v.begin(), v.end());

        ll abc = v[0] + v[1] + v[2];

        std::cout << ((abc % 3) > 0) << std::endl;
    }
    return 0;
}
