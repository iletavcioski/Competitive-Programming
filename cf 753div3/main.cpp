#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> v;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            if (num % 2) {
                odd++;
            }
        }
        std::cout << odd / 2 << std::endl;
    }
    return 0;
}
