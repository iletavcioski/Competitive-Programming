#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    long long x;
    std::cin >> x;
    long long arr[n];
    long long max = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        max = std::max(arr[i], max);
    }

    long long l = 0;
    long long r = 1e18;
    long long res = 0;
    while (l <= r) {
        //std::cout << l << " " << std::cout << r << std::endl;
        long long mid = (l + r) / 2;

        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt += mid / arr[i];
            if (cnt > 1e18) {
                break;
            }
        }

        if (cnt >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << res << std::endl;
    return 0;
}