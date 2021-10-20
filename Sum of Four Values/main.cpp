#include <iostream>
#include <unordered_map>
#include <algorithm>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    int n, x;
    std::cin >> n >> x;
    int array[n];
    int arr[n];
    std::unordered_map<int, std::pair<int, int> > map;

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        arr[i] = array[i];
    }

    std::sort(arr, arr + n);
    if ((long long)x > (long long)arr[n - 1] + (long long)arr[n - 2] + (long long)arr[n - 3] + (long long)arr[n - 4]) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            map[array[i] + array[j]] = {i + 1, j + 1};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int num = x - array[i] - array[j];
            if (map.count(num) && map[num].first != i + 1 && map[num].first != j + 1 && map[num].second != i + 1 && map[num].second != j + 1) {
                std::cout << map[num].first << " " << map[num].second << " " << i + 1 << " " << j + 1 << std::endl;
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
