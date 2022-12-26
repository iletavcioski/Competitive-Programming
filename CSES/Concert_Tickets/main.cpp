#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, q;
    std::cin >> n >> q;
    std::map<int, int> map;

    for (int i = 0; i < n; i++) {
        int tickets;
        std::cin >> tickets;
        map[tickets]++;
    }

    while (q--) {
        int purchase;
        std::cin >> purchase;

        auto it = map.lower_bound(purchase);
        auto first_it = map.begin();
        if (it == map.end() && first_it == map.end()) {
            std::cout << -1 << std::endl;
            continue;
        }
        if (it == map.end()) {
            it--;
        }
        if (it->first == first_it->first && it->first > purchase) {
            std::cout << -1 << std::endl;
        } else {
            if (it->first > purchase) {
                it--;
            }
            std::cout << it->first << std::endl;
            map[it->first]--;
            if (!map[it->first]) {
                map.erase(it);
            }
        }
    }
    return 0;
}
