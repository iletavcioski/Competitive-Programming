#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    int x;
    std::cin >> x;

    long long arr[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    long long res = 0;
    long long l = 0, r = sum;
    while (l <= r) {
        long long mid = (l + r) / 2;
        int k = 1;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                k = x + 1;
            }
            if (cnt + arr[i] > mid) {
                cnt = arr[i];
                k++;
            } else {
                cnt += arr[i];
            }
            if (k > x) {
                break;
            }
        }

        if (k > x) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }

    std::cout << res << std::endl;

    return 0;
}