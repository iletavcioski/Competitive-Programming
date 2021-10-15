#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> array;
        array.resize(n);
        int max = -1e9;
        int min = 1e9;
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
            max = std::max(array[i], max);
            min = std::min(array[i], min);
        }

        int end = max - min;
        int res = -1;
        for (int i = end; i >= 1; i--) {
            bool cant = false;
            for (int j = 0; j < n; j++) {
                if ((array[j] - min) % i) {
                    cant = true;
                    break;
                }
            }
            if (!cant) {
                res = i;
                break;
            }
        }
        std::cout << res << std::endl;
    }

    return 0;
}