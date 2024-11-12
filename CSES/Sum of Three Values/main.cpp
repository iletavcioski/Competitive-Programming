#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, x;
    std::cin >> n >> x;
    std::unordered_map<int, int> map;
    
    int array[5001];
    std::pair<int,int> arr[5001];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        map[array[i]] = i + 1;
        arr[i] = {array[i], i + 1};
    }

    std::sort(arr, arr + n);
    if ((long long)x > (long long)arr[n - 1].first + (long long)arr[n - 2].first + (long long)arr[n - 3].first) {
        std::cout << "IMPOSSIBLE" << "\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int num = x - arr[i].first;
        if (num < 0) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (num - arr[j].first < 0) {
                continue;
            }
            if (map[num - arr[j].first] && map[num - arr[j].first] != arr[i].second && map[num - arr[j].first] != arr[j].second) {
                std::cout << map[x - arr[i].first - arr[j].first] << " " << arr[i].second << " " << arr[j].second << "\n";
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE" << "\n";
    return 0;
}
