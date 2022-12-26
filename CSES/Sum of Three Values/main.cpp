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
    int arr[5001];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        map[array[i]] = i + 1;
        arr[i] = array[i];
    }

    std::sort(arr, arr + n);
    if ((long long)x > (long long)arr[n - 1] + (long long)arr[n - 2] + (long long)arr[n - 3]) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int num = x - array[i];
        for (int j = i + 1; j < n; j++) {
            if (map[num - array[j]] && map[num - array[j]] != i + 1 && map[num - array[j]] != j + 1) {
                std::cout << map[x - array[i] - array[j]] << " " << i + 1 << " " << j + 1 << std::endl;
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
