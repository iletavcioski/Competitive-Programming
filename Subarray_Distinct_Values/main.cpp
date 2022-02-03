#include <iostream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n;
    std::cin >> n;
    long long x;
    std::cin >> x;

    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long res = 0;
    long long cnt = 0;
    std::map<int,int> map;
    cnt = 0;
    long long l = 0, r = 0;
    while (r < n) {
        /*(if (cnt <= x) {
            int s = r - l + 1;
            res += ((s * (s + 1))/2);
        }
        */
        if (!map[arr[r]]) {
            map[arr[r]]++;
            cnt++;
        } else {
            map[arr[r]]++;
        }
        if (cnt <= x) {
            res += (std::max((r - 1) - l + 1, 0LL) + 1);
        }
        r++;

        while (cnt > x && l < n) {
            if (map[arr[l]] == 1) {
                map[arr[l]]--;
                cnt--;
            } else {
                map[arr[l]]--;
            }
            l++;
            if (cnt <= x) {
                res += (std::max((r - 2) - l + 1, 0LL) + 1);
            }

        }
    }
    std::cout << res << std::endl;
    return 0;
}