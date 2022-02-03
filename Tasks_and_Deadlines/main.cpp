#include <iostream>
#include <algorithm>
#include <array>

bool compare(const std::array<int, 2> a, const std::array<int, 2> b) {
    return a[0] < b[0];
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;

    std::array<int, 2> arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i][0] >> arr[i][1];
    }

    std::sort(arr, arr + n, compare);

    long long cnt = 0;
    long long res = 0;

    for (int i = 0; i < n; i++) {
        cnt += arr[i][0];
        res += (arr[i][1] - cnt);
    }

    std::cout << res << std::endl;
    return 0;
}