#include <iostream>
#include <set>

int main() {
    std::multiset<int> set;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;

        auto it = set.upper_bound(num);
        if (it != set.end()) {
            set.erase(it);
            set.insert(num);
        } else {
            set.insert(num);
        }
    }

    std::cout << set.size() << std::endl;
    return 0;
}