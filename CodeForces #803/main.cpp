#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        long long arr[n];
        std::vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] + arr[i + 1] < arr[i]) {
                vis[i] = true;
            }
        }

        for (int i = 1; i < )
        std::cout << res << std::endl;
    }
    return 0;
}